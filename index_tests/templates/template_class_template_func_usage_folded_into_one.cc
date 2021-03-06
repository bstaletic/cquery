template<typename T>
struct Foo {
  template<typename R>
  static int foo() {
    return 3;
  }
};

int a = Foo<int>::foo<float>();
int b = Foo<bool>::foo<double>();

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
      "definition_extent": "2:1-7:2",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [0],
      "vars": [],
      "instances": [],
      "uses": ["9:9-9:12", "10:9-10:12"]
    }, {
      "id": 1,
      "usr": 17,
      "short_name": "",
      "detailed_name": "",
      "kind": 0,
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [0, 1],
      "uses": []
    }],
  "funcs": [{
      "id": 0,
      "usr": 9034026360701857235,
      "short_name": "foo",
      "detailed_name": "int Foo::foo()",
      "kind": 18,
      "storage": 3,
      "declarations": [],
      "definition_spelling": "4:14-4:17",
      "definition_extent": "4:3-6:4",
      "declaring_type": 0,
      "base": [],
      "derived": [],
      "locals": [],
      "callers": ["-1@9:19-9:22", "-1@10:20-10:23"],
      "callees": []
    }],
  "vars": [{
      "id": 0,
      "usr": 16721564935990383768,
      "short_name": "a",
      "detailed_name": "int a",
      "hover": "int a = Foo<int>::foo<float>()",
      "declarations": [],
      "definition_spelling": "9:5-9:6",
      "definition_extent": "9:1-9:31",
      "variable_type": 1,
      "uses": [],
      "parent_id": 18446744073709551615,
      "parent_kind": 0,
      "kind": 13,
      "storage": 1
    }, {
      "id": 1,
      "usr": 12028309045033782423,
      "short_name": "b",
      "detailed_name": "int b",
      "hover": "int b = Foo<bool>::foo<double>()",
      "declarations": [],
      "definition_spelling": "10:5-10:6",
      "definition_extent": "10:1-10:33",
      "variable_type": 1,
      "uses": [],
      "parent_id": 18446744073709551615,
      "parent_kind": 0,
      "kind": 13,
      "storage": 1
    }]
}
*/
