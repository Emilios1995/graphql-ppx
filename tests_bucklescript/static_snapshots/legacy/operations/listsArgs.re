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
    type t = {. "listsInput": string};
    type t_variables = {
      .
      "nullableOfNullable": Js.Nullable.t(array(Js.Nullable.t(string))),
      "nullableOfNonNullable": Js.Nullable.t(array(string)),
      "nonNullableOfNullable": array(Js.Nullable.t(string)),
      "nonNullableOfNonNullable": array(string),
    };
  };
  /**The GraphQL query string*/
  let query = "query ($nullableOfNullable: [String], $nullableOfNonNullable: [String!], $nonNullableOfNullable: [String]!, $nonNullableOfNonNullable: [String!]!)  {\nlistsInput(arg: {nullableOfNullable: $nullableOfNullable, nullableOfNonNullable: $nullableOfNonNullable, nonNullableOfNullable: $nonNullableOfNullable, nonNullableOfNonNullable: $nonNullableOfNonNullable})  \n}\n";
  type t = {. "listsInput": string};
  type t_variables = {
    .
    "nullableOfNullable": option(array(option(string))),
    "nullableOfNonNullable": option(array(string)),
    "nonNullableOfNullable": array(option(string)),
    "nonNullableOfNonNullable": array(string),
  };
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => {
    let listsInput = {
      let value = value##listsInput;
      value;
    };
    {"listsInput": listsInput};
  };
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => {
    let listsInput = {
      let value = value##listsInput;
      value;
    };
    {"listsInput": listsInput};
  };
  let serializeVariables: t_variables => Raw.t_variables =
    inp => {
      "nullableOfNullable":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return(
                (
                  a =>
                    Array.map(
                      b =>
                        (
                          a =>
                            switch (a) {
                            | None => Js.Nullable.undefined
                            | Some(b) => Js.Nullable.return((a => a)(b))
                            }
                        )(
                          b,
                        ),
                      a,
                    )
                )(
                  b,
                ),
              )
            }
        )(
          inp##nullableOfNullable,
        ),
      "nullableOfNonNullable":
        (
          a =>
            switch (a) {
            | None => Js.Nullable.undefined
            | Some(b) =>
              Js.Nullable.return((a => Array.map(b => (a => a)(b), a))(b))
            }
        )(
          inp##nullableOfNonNullable,
        ),
      "nonNullableOfNullable":
        (
          a =>
            Array.map(
              b =>
                (
                  a =>
                    switch (a) {
                    | None => Js.Nullable.undefined
                    | Some(b) => Js.Nullable.return((a => a)(b))
                    }
                )(
                  b,
                ),
              a,
            )
        )(
          inp##nonNullableOfNullable,
        ),
      "nonNullableOfNonNullable":
        (a => Array.map(b => (a => a)(b), a))(
          inp##nonNullableOfNonNullable,
        ),
    };
  let make =
      (
        ~nullableOfNullable=?,
        ~nullableOfNonNullable=?,
        ~nonNullableOfNullable,
        ~nonNullableOfNonNullable,
        (),
      ) => {
    "query": query,
    "variables":
      serializeVariables(
        {
          "nullableOfNullable": nullableOfNullable,
          "nullableOfNonNullable": nullableOfNonNullable,
          "nonNullableOfNullable": nonNullableOfNullable,
          "nonNullableOfNonNullable": nonNullableOfNonNullable,
        }: t_variables,
      ),
    "parse": parse,
  }
  and makeVariables =
      (
        ~nullableOfNullable=?,
        ~nullableOfNonNullable=?,
        ~nonNullableOfNullable,
        ~nonNullableOfNonNullable,
        (),
      ) =>
    serializeVariables(
      {
        "nullableOfNullable": nullableOfNullable,
        "nullableOfNonNullable": nullableOfNonNullable,
        "nonNullableOfNullable": nonNullableOfNullable,
        "nonNullableOfNonNullable": nonNullableOfNonNullable,
      }: t_variables,
    );
  let makeWithVariables = variables => {
    "query": query,
    "variables": serializeVariables(variables),
    "parse": parse,
  };
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
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
