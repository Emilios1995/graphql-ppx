module rec StringIntFragment = [%graphql
  {|
  fragment scalarFragment on VariousScalars @ppxCustom(module: "StringInt") {
    string
    int
  }
|}
]
and StringInt: {
  type t = (string, int);
  let parse: StringIntFragment.t => t;
  let serialize: t => StringIntFragment.t;
} = {
  type t = (string, int);
  let parse = ({StringIntFragment.string, int}) => (string, int);
  let serialize = ((string, int)) => {StringIntFragment.string, int};
};

let test = () => Alcotest.fail("write a test");

let tests = [("test is written", `Quick, test)];
