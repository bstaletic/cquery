template<typename T>
void accept(T);

void foo() {
  accept(1);
  accept(true);
}

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 13420564603121289209,
      "short_name": "T",
      "detailed_name": "T",
      "kind": 0,
      "definition_spelling": "1:19-1:20",
      "definition_extent": "1:10-1:20",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [],
      "uses": ["2:13-2:14"]
    }],
  "funcs": [{
      "id": 0,
      "usr": 10585861037135727329,
      "short_name": "accept",
      "detailed_name": "void accept(T)",
      "kind": 12,
      "storage": 1,
      "declarations": [{
          "spelling": "2:6-2:12",
          "extent": "2:1-2:15",
          "content": "void accept(T)",
          "param_spellings": ["2:14-2:14"]
        }],
      "base": [],
      "derived": [],
      "locals": [],
      "callers": ["1@5:3-5:9", "1@6:3-6:9"],
      "callees": []
    }, {
      "id": 1,
      "usr": 4259594751088586730,
      "short_name": "foo",
      "detailed_name": "void foo()",
      "kind": 12,
      "storage": 1,
      "declarations": [],
      "definition_spelling": "4:6-4:9",
      "definition_extent": "4:1-7:2",
      "base": [],
      "derived": [],
      "locals": [],
      "callers": [],
      "callees": ["0@5:3-5:9", "0@6:3-6:9"]
    }],
  "vars": []
}
*/
