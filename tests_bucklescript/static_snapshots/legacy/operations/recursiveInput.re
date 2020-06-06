[@ocaml.ppx.context
  {
    tool_name: "migrate_driver",
    include_dirs: [],
    load_path: [],
    open_modules: [],
    for_package: None,
    debug: false,
    use_threads: false,
    use_vmthreads: false,
    recursive_types: false,
    principal: false,
    transparent_modules: false,
    unboxed_types: false,
    unsafe_string: false,
    cookies: [],
  }
];
module MyQuery = {
  module Raw = {
    type t = {. "recursiveInput": string};
    type t_variables = {. "arg": t_variables_RecursiveInput}
    and t_variables_RecursiveInput = {
      .
      "otherField": Js.Nullable.t(string),
      "inner": Js.Nullable.t(t_variables_RecursiveInput),
      "enum": Js.Nullable.t(string),
    };
  };
  /**The GraphQL query string*/
  let query = "query ($arg: RecursiveInput!)  {\nrecursiveInput(arg: $arg)  \n}\n";
  type t = {. "recursiveInput": string};
  type t_variables = {. "arg": t_variables_RecursiveInput}
  and t_variables_RecursiveInput = {
    .
    "otherField": option(string),
    "inner": option(t_variables_RecursiveInput),
    "enum": option([ | `FIRST | `SECOND | `THIRD]),
  };
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let recursiveInput = {
      let value = value##recursiveInput;
      value;
    };
    {"recursiveInput": recursiveInput};
  };
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let recursiveInput = {
      let value = value##recursiveInput;
      value;
    };
    {"recursiveInput": recursiveInput};
  };
  let rec serializeVariables: t_variables => Raw.t_variables =
    inp => {"arg": (a => serializeInputObjectRecursiveInput(a))(inp##arg)}
  and serializeInputObjectRecursiveInput:
    t_variables_RecursiveInput => Raw.t_variables_RecursiveInput =
    inp => {
      "otherField":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) => Js.Nullable.return((a => a)(b))
            }
        )(
          inp##otherField,
        ),
      "inner":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (a => serializeInputObjectRecursiveInput(a))(b),
              )
            }
        )(
          inp##inner,
        ),
      "enum":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    switch (a) {
                    | `FIRST => "FIRST"
                    | `SECOND => "SECOND"
                    | `THIRD => "THIRD"
                    }
                )(
                  b,
                ),
              )
            }
        )(
          inp##enum,
        ),
    };
  let make = (~arg, ()) => {
    "query": query,
    "variables": serializeVariables({"arg": arg}: t_variables),
    "parse": parse,
  }
  and makeVariables = (~arg, ()) =>
    serializeVariables({"arg": arg}: t_variables)
  and makeInputObjectRecursiveInput =
      (~otherField=?, ~inner=?, ~enum=?, ()): t_variables_RecursiveInput => {
    "otherField": otherField,
    "inner": inner,
    "enum": enum,
  };
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec _graphql_RecursiveInput_47;
    /**```
RecursiveInput {
  otherField: String
  inner: RecursiveInput
  enum: SampleField
}
```*/
    let _graphql_RecursiveInput_47: _graphql_RecursiveInput_47 = Obj.magic(0);
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module MyQuery {
  /**
  The GraphQL query string
  */
  let query: string;

  /**
  This is the main type of the result you will get back.
  You can hover above the identifier key (e.g. query or mutation) to see the fully generated type for your module.
  */
  type t;

  /**
  Parse the JSON GraphQL data to ReasonML data types
  */
  let parse: Raw.t => t;

  /**
  Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data
  */
  let serialize: t => Raw.t;

  /**
  This is the JSON compatible type of the GraphQL data.
  It should not be necessary to access the types inside for normal use cases.
  */
  module Raw: { type t; };
}
```*/
    let graphql_module: graphql_module = Obj.magic(0);
  };
};
