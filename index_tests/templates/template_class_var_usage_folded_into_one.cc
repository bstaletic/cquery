template<typename T>
struct Foo {
  static constexpr int var = 3;
};

int a = Foo<int>::var;
int b = Foo<bool>::var;

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 10528472276654770367,
      "short_name": "Foo",
      "detailed_name": "Foo",
      "kind": 7,
      "definition_spelling": "2:8-2:11",
      "definition_extent": "2:1-4:2",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [],
      "uses": ["2:8-2:11", "6:9-6:12", "7:9-7:12"]
    }],
  "funcs": [],
  "vars": [{
      "id": 0,
      "usr": 13545144895171991916,
      "short_name": "var",
      "detailed_name": "const int Foo::var",
      "hover": "const int Foo::var = 3",
      "declaration": "3:24-3:27",
      "kind": 21,
      "uses": ["3:24-3:27", "6:19-6:22", "7:20-7:23"]
    }, {
      "id": 1,
      "usr": 16721564935990383768,
      "short_name": "a",
      "detailed_name": "int a",
      "hover": "int a = Foo<int>::var",
      "definition_spelling": "6:5-6:6",
      "definition_extent": "6:1-6:22",
      "kind": 13,
      "uses": ["6:5-6:6"]
    }, {
      "id": 2,
      "usr": 12028309045033782423,
      "short_name": "b",
      "detailed_name": "int b",
      "hover": "int b = Foo<bool>::var",
      "definition_spelling": "7:5-7:6",
      "definition_extent": "7:1-7:23",
      "kind": 13,
      "uses": ["7:5-7:6"]
    }]
}
*/
