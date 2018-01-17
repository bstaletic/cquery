namespace ns {
  enum VarType {};

  template<typename _>
  struct Holder {
    static constexpr VarType static_var = (VarType)0x0;
  };

  template<typename _>
  const typename VarType Holder<_>::static_var;


  int Foo = Holder<int>::static_var;
  int Foo2 = Holder<int>::static_var;
}

/*
OUTPUT:
{
  "includes": [],
  "skipped_by_preprocessor": [],
  "types": [{
      "id": 0,
      "usr": 1532099849728741556,
      "short_name": "VarType",
      "detailed_name": "ns::VarType",
      "kind": 5,
      "definition_spelling": "2:8-2:15",
      "definition_extent": "2:3-2:18",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [],
      "instances": [0],
      "uses": ["2:8-2:15", "6:22-6:29", "6:44-6:51", "10:18-10:25"]
    }, {
      "id": 1,
      "usr": 12688716854043726585,
      "short_name": "Holder",
      "detailed_name": "ns::Holder",
      "kind": 7,
      "definition_spelling": "5:10-5:16",
      "definition_extent": "5:3-7:4",
      "parents": [],
      "derived": [],
      "types": [],
      "funcs": [],
      "vars": [0],
      "instances": [],
      "uses": ["5:10-5:16", "10:26-10:32", "13:13-13:19", "14:14-14:20"]
    }],
  "funcs": [],
  "vars": [{
      "id": 0,
      "usr": 4731849186641714451,
      "short_name": "static_var",
      "detailed_name": "const ns::VarType ns::Holder::static_var",
      "hover": "const ns::VarType ns::Holder::static_var = (VarType)0x0",
      "declaration": "6:30-6:40",
      "definition_spelling": "10:37-10:47",
      "definition_extent": "9:3-10:47",
      "variable_type": 0,
      "declaring_type": 1,
      "kind": 21,
      "uses": ["6:30-6:40", "10:37-10:47", "13:26-13:36", "14:27-14:37"]
    }, {
      "id": 1,
      "usr": 12898699035586282159,
      "short_name": "Foo",
      "detailed_name": "int ns::Foo",
      "hover": "int ns::Foo = Holder<int>::static_var",
      "definition_spelling": "13:7-13:10",
      "definition_extent": "13:3-13:36",
      "kind": 13,
      "uses": ["13:7-13:10"]
    }, {
      "id": 2,
      "usr": 9008550860229740818,
      "short_name": "Foo2",
      "detailed_name": "int ns::Foo2",
      "hover": "int ns::Foo2 = Holder<int>::static_var",
      "definition_spelling": "14:7-14:11",
      "definition_extent": "14:3-14:37",
      "kind": 13,
      "uses": ["14:7-14:11"]
    }]
}
*/
