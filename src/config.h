#pragma once

#include "serializer.h"

#include <string>

/*
The language client plugin needs to send initialization options in the
`initialize` request to the cquery language server. The only required option is
`cacheDirectory`, which is where index files will be stored.

  {
    "initializationOptions": {
      "cacheDirectory": "/tmp/cquery"
    }
  }

If necessary, the command line option --init can be used to override
initialization options specified by the client. For example, in shell syntax:

  '--init={"indexWhitelist": ["."], "index": {"comments": 2}}'
*/
struct Config {
  // Root directory of the project. **Not available for configuration**
  std::string projectRoot;
  // Directory containing compile_commands.json.
  std::string compilationDatabaseDirectory;
  // Cache directory for indexed files.
  std::string cacheDirectory;
  // Cache serialization format.
  //
  // "json" generates `cacheDirectory/.../xxx.json` files which can be pretty
  // printed with jq.
  //
  // "msgpack" uses a compact binary serialization format (the underlying wire
  // format is [MessagePack](https://msgpack.org/index.html)) which typically
  // takes only 60% of the corresponding JSON size, but is difficult to inspect.
  // msgpack does not store map keys and you need to re-index whenever a struct
  // member has changed.
  SerializeFormat cacheFormat = SerializeFormat::Json;
  // Value to use for clang -resource-dir if not present in
  // compile_commands.json.
  //
  // cquery includes a resource directory, this should not need to be configured
  // unless you're using an esoteric configuration. Consider reporting a bug and
  // fixing upstream instead of configuring this.
  //
  // Example value: "/path/to/lib/clang/5.0.1/"
  std::string resourceDirectory;

  // Additional arguments to pass to clang.
  std::vector<std::string> extraClangArguments;

  // If a translation unit's absolute path matches any EMCAScript regex in the
  // whitelist, or does not match any regex in the blacklist, it will be indexed.
  // To only index files in the whitelist, add ".*" to the blacklist.
  // `std::regex_search(path, regex, std::regex_constants::match_any)`
  //
  // Example: `ash/.*\.cc`
  std::vector<std::string> indexWhitelist;
  std::vector<std::string> indexBlacklist;
  // If true, project paths that were skipped by the whitelist/blacklist will
  // be logged.
  bool logSkippedPathsForIndex = false;

  // Maximum workspace search results.
  int maxWorkspaceSearchResults = 500;
  // If true, workspace search results will be dynamically rescored/reordered
  // as the search progresses. Some clients do their own ordering and assume
  // that the results stay sorted in the same order as the search progresses.
  bool sortWorkspaceSearchResults = true;

  // Force a certain number of indexer threads. If less than 1 a default value
  // is be used (80% number of CPU cores).
  int indexerCount = 0;
  // If false, the indexer will be disabled.
  bool enableIndexing = true;

  // If true, cquery will send progress reports while indexing
  // How often should cquery send progress report messages?
  //  -1: never
  //   0: as often as possible
  //   xxx: at most every xxx milliseconds
  //
  // Empty progress reports (ie, idle) are delivered as often as they are
  // available and may exceed this value.
  //
  // This does not guarantee a progress report will be delivered every
  // interval; it could take significantly longer if cquery is completely idle.
  int progressReportFrequencyMs = 500;

  // If true, document links are reported for #include directives.
  bool showDocumentLinksOnIncludes = true;

  // Maximum path length to show in completion results. Paths longer than this
  // will be elided with ".." put at the front. Set to 0 or a negative number
  // to disable eliding.
  int includeCompletionMaximumPathLength = 30;
  // Whitelist that file paths will be tested against. If a file path does not
  // end in one of these values, it will not be considered for auto-completion.
  // An example value is { ".h", ".hpp" }
  //
  // This is significantly faster than using a regex.
  std::vector<std::string> includeCompletionWhitelistLiteralEnding = {
      ".h", ".hpp", ".hh"};
  // Regex patterns to match include completion candidates against. They
  // receive the absolute file path.
  //
  // For example, to hide all files in a /CACHE/ folder, use ".*/CACHE/.*"
  std::vector<std::string> includeCompletionWhitelist;
  std::vector<std::string> includeCompletionBlacklist;

  // If true, diagnostics from a full document parse will be reported.
  bool diagnosticsOnParse = true;
  // If true, diagnostics from code completion will be reported.
  bool diagnosticsOnCodeCompletion = true;

  // Enables code lens on parameter and function variables.
  bool codeLensOnLocalVariables = true;

  // Version of the client. If undefined the version check is skipped. Used to
  // inform users their vscode client is too old and needs to be updated.
  optional<int> clientVersion;

  struct ClientCapability {
    // TextDocumentClientCapabilities.completion.completionItem.snippetSupport
    bool snippetSupport = false;
  };
  ClientCapability client;

  struct Completion {
    // If true, filter and sort completion response. cquery filters and sorts
    // completions to try to be nicer to clients that can't handle big numbers
    // of completion candidates. This behaviour can be disabled by specifying
    // false for the option. This option is the most useful for LSP clients
    // that implement their own filtering and sorting logic.
    bool filterAndSort = true;
  };
  Completion completion;

  struct Index {
    // 0: none, 1: doxygen, 2: all comments
    // Plugin support for clients:
    // - https://github.com/emacs-lsp/lsp-ui
    // - https://github.com/emacs-lsp/lsp-mode/pull/224
    // - https://github.com/autozimu/LanguageClient-neovim/issues/224
    int comments = 2;
  };
  Index index;

  //// For debugging

  // Dump AST after parsing if some pattern matches the source filename.
  std::vector<std::string> dumpAST;
};
MAKE_REFLECT_STRUCT(Config::ClientCapability, snippetSupport);
MAKE_REFLECT_STRUCT(Config::Completion, filterAndSort);
MAKE_REFLECT_STRUCT(Config::Index, comments);
MAKE_REFLECT_STRUCT(Config,
                    compilationDatabaseDirectory,
                    cacheDirectory,
                    cacheFormat,
                    resourceDirectory,

                    extraClangArguments,

                    indexWhitelist,
                    indexBlacklist,
                    logSkippedPathsForIndex,

                    maxWorkspaceSearchResults,
                    sortWorkspaceSearchResults,

                    indexerCount,
                    enableIndexing,
                    progressReportFrequencyMs,

                    includeCompletionMaximumPathLength,
                    includeCompletionWhitelistLiteralEnding,
                    includeCompletionWhitelist,
                    includeCompletionBlacklist,

                    showDocumentLinksOnIncludes,

                    diagnosticsOnParse,
                    diagnosticsOnCodeCompletion,

                    codeLensOnLocalVariables,

                    clientVersion,

                    client,
                    completion,
                    index,

                    dumpAST);

// Expected client version. We show an error if this doesn't match.
constexpr const int kExpectedClientVersion = 3;
