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
type scalars = {
  string,
  int,
};

type dog = {
  name: string,
  barkVolume: float,
};

type oneFieldQuery = {nullableString: option(string)};
module MyQuery = {
  module Raw = {
    type t_variousScalars = {
      __typename: string,
      string,
      int,
    };
    type t = {variousScalars: t_variousScalars};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "query   {\nvariousScalars  {\n__typename  \nstring  \nint  \n}\n\n}\n";
  type t = {variousScalars: scalars};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      variousScalars: {
        let value = (value: Raw.t).variousScalars;
        (
          {
            __typename: {
              let value = (value: Raw.t_variousScalars).__typename;
              value;
            },
            string: {
              let value = (value: Raw.t_variousScalars).string;
              value;
            },
            int: {
              let value = (value: Raw.t_variousScalars).int;
              value;
            },
          }: scalars
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let variousScalars = {
        let value = (value: t).variousScalars;
        (
          {
            let int = {
              let value = (value: scalars).int;
              value;
            }
            and string = {
              let value = (value: scalars).string;
              value;
            }
            and __typename = {
              let value = (value: scalars).__typename;
              value;
            };
            {__typename, string, int};
          }: Raw.t_variousScalars
        );
      };
      {variousScalars: variousScalars};
    }: Raw.t
  );
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
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
module OneFieldQuery = {
  module Raw = {
    type t_variousScalars = {
      __typename: string,
      nullableString: Js.Nullable.t(string),
    };
    type t = {variousScalars: t_variousScalars};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "query   {\nvariousScalars  {\n__typename  \nnullableString  \n}\n\n}\n";
  type t_variousScalars = {
    __typename: string,
    nullableString: option(string),
  };
  type t = {variousScalars: t_variousScalars};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      variousScalars: {
        let value = (value: Raw.t).variousScalars;
        (
          {
            __typename: {
              let value = (value: Raw.t_variousScalars).__typename;
              value;
            },
            nullableString: {
              let value = (value: Raw.t_variousScalars).nullableString;
              switch (Js.toOption(value)) {
              | Some(value) => Some(value)
              | None => None
              };
            },
          }: t_variousScalars
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let variousScalars = {
        let value = (value: t).variousScalars;
        (
          {
            let nullableString = {
              let value = (value: t_variousScalars).nullableString;
              switch (value) {
              | Some(value) => Js.Nullable.return(value)
              | None => Js.Nullable.null
              };
            }
            and __typename = {
              let value = (value: t_variousScalars).__typename;
              value;
            };
            {__typename, nullableString};
          }: Raw.t_variousScalars
        );
      };
      {variousScalars: variousScalars};
    }: Raw.t
  );
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module OneFieldQuery {
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
module ExternalFragmentQuery = {
  module Fragment = {
    /**The GraphQL query string*/
    let query = "fragment Fragment on VariousScalars   {\n__typename  \nstring  \nint  \n}\n";
    module Raw = {
      type t = {
        __typename: string,
        string,
        int,
      };
      type nonrec t_VariousScalars = t;
    };
    type t = {
      __typename: string,
      string,
      int,
    };
    type nonrec t_VariousScalars = t;
    /**Parse the JSON GraphQL data to ReasonML data types*/
    let parse = (value: Raw.t): t => (
      {
        __typename: {
          let value = (value: Raw.t).__typename;
          value;
        },
        string: {
          let value = (value: Raw.t).string;
          value;
        },
        int: {
          let value = (value: Raw.t).int;
          value;
        },
      }: t
    );
    let verifyArgsAndParse = (value: Raw.t) => parse(value);
    /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
    let serialize = (value: t): Raw.t => (
      {
        let int = {
          let value = (value: t).int;
          value;
        }
        and string = {
          let value = (value: t).string;
          value;
        }
        and __typename = {
          let value = (value: t).__typename;
          value;
        };
        {__typename, string, int};
      }: Raw.t
    );
    let name = "Fragment";
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql;
      /**```
VariousScalars {
  nullableString: String
  string: String!
  nullableInt: Int
  int: Int!
  nullableFloat: Float
  float: Float!
  nullableBoolean: Boolean
  boolean: Boolean!
  nullableID: ID
  id: ID!
}
```*/
      let graphql: graphql = Obj.magic(0);
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module ExternalFragmentQuery {
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
  module Untitled1 = {
    module Raw = {
      type t = {variousScalars: Fragment.Raw.t};
      type t_variables = unit;
    };
    /**The GraphQL query string*/
    let query =
      (
        ("query   {\nvariousScalars  {\n..." ++ Fragment.name)
        ++ "   \n}\n\n}\n"
      )
      ++ Fragment.query;
    type t = {variousScalars: Fragment.t};
    type t_variables = unit;
    /**Parse the JSON GraphQL data to ReasonML data types*/
    let parse = (value: Raw.t): t => (
      {
        variousScalars: {
          let value = (value: Raw.t).variousScalars;
          Fragment.verifyArgsAndParse(value);
        },
      }: t
    );
    /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
    let serialize = (value: t): Raw.t => (
      {
        let variousScalars = {
          let value = (value: t).variousScalars;
          Fragment.serialize(value);
        };
        {variousScalars: variousScalars};
      }: Raw.t
    );
    let makeVariables = () => ();
    let makeDefaultVariables = () => makeVariables();
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module ExternalFragmentQuery {
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
};
module InlineFragmentQuery = {
  module Raw = {
    type t_dogOrHuman_Dog = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type t_dogOrHuman;
    type t = {dogOrHuman: t_dogOrHuman};
    type t_variables = unit;
  };
  /**The GraphQL query string*/
  let query = "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n__typename  \nname  \nbarkVolume  \n}\n\n}\n\n}\n";
  type t_dogOrHuman_Dog = {
    __typename: string,
    name: string,
    barkVolume: float,
  };
  type t_dogOrHuman = [
    | `FutureAddedValue(Js.Json.t)
    | `Dog(t_dogOrHuman_Dog)
  ];
  type t = {dogOrHuman: t_dogOrHuman};
  type t_variables = unit;
  /**Parse the JSON GraphQL data to ReasonML data types*/
  let parse = (value: Raw.t): t => (
    {
      dogOrHuman: {
        let value = (value: Raw.t).dogOrHuman;
        let typename: string =
          Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
        (
          switch (typename) {
          | "Dog" =>
            `Dog(
              {
                let value: Raw.t_dogOrHuman_Dog = Obj.magic(value);
                (
                  {
                    __typename: {
                      let value = (value: Raw.t_dogOrHuman_Dog).__typename;
                      value;
                    },
                    name: {
                      let value = (value: Raw.t_dogOrHuman_Dog).name;
                      value;
                    },
                    barkVolume: {
                      let value = (value: Raw.t_dogOrHuman_Dog).barkVolume;
                      value;
                    },
                  }: t_dogOrHuman_Dog
                );
              },
            )
          | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
          }: t_dogOrHuman
        );
      },
    }: t
  );
  /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
  let serialize = (value: t): Raw.t => (
    {
      let dogOrHuman = {
        let value = (value: t).dogOrHuman;
        switch (value) {
        | `Dog(value) => (
            Obj.magic(
              {
                let barkVolume = {
                  let value = (value: t_dogOrHuman_Dog).barkVolume;
                  value;
                }
                and name = {
                  let value = (value: t_dogOrHuman_Dog).name;
                  value;
                }
                and __typename = {
                  let value = (value: t_dogOrHuman_Dog).__typename;
                  value;
                };
                {__typename: "Dog", name, barkVolume};
              }: Raw.t_dogOrHuman_Dog,
            ): Raw.t_dogOrHuman
          )
        | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
        };
      };
      {dogOrHuman: dogOrHuman};
    }: Raw.t
  );
  let makeVariables = () => ();
  let makeDefaultVariables = () => makeVariables();
  external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
  external toJson: Raw.t => Js.Json.t = "%identity";
  module Z__INTERNAL = {
    type root = t;
    type nonrec graphql_module;
    /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module InlineFragmentQuery {
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
module UnionExternalFragmentQuery = {
  module DogFragment = {
    /**The GraphQL query string*/
    let query = "fragment DogFragment on Dog   {\n__typename  \nname  \nbarkVolume  \n}\n";
    module Raw = {
      type t = {
        __typename: string,
        name: string,
        barkVolume: float,
      };
      type nonrec t_Dog = t;
    };
    type t = {
      __typename: string,
      name: string,
      barkVolume: float,
    };
    type nonrec t_Dog = t;
    /**Parse the JSON GraphQL data to ReasonML data types*/
    let parse = (value: Raw.t): t => (
      {
        __typename: {
          let value = (value: Raw.t).__typename;
          value;
        },
        name: {
          let value = (value: Raw.t).name;
          value;
        },
        barkVolume: {
          let value = (value: Raw.t).barkVolume;
          value;
        },
      }: t
    );
    let verifyArgsAndParse = (value: Raw.t) => parse(value);
    /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
    let serialize = (value: t): Raw.t => (
      {
        let barkVolume = {
          let value = (value: t).barkVolume;
          value;
        }
        and name = {
          let value = (value: t).name;
          value;
        }
        and __typename = {
          let value = (value: t).__typename;
          value;
        };
        {__typename, name, barkVolume};
      }: Raw.t
    );
    let name = "DogFragment";
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql;
      /**```
Dog {
  name: String!
  barkVolume: Float!
}
```*/
      let graphql: graphql = Obj.magic(0);
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module UnionExternalFragmentQuery {
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
  module Untitled1 = {
    module Raw = {
      type t_dogOrHuman;
      type t = {dogOrHuman: t_dogOrHuman};
      type t_variables = unit;
    };
    /**The GraphQL query string*/
    let query =
      (
        (
          "query   {\ndogOrHuman  {\n__typename\n...on Dog   {\n..."
          ++ DogFragment.name
        )
        ++ "   \n}\n\n}\n\n}\n"
      )
      ++ DogFragment.query;
    type t_dogOrHuman = [
      | `FutureAddedValue(Js.Json.t)
      | `Dog(DogFragment.t)
    ];
    type t = {dogOrHuman: t_dogOrHuman};
    type t_variables = unit;
    /**Parse the JSON GraphQL data to ReasonML data types*/
    let parse = (value: Raw.t): t => (
      {
        dogOrHuman: {
          let value = (value: Raw.t).dogOrHuman;
          let typename: string =
            Obj.magic(Js.Dict.unsafeGet(Obj.magic(value), "__typename"));
          (
            switch (typename) {
            | "Dog" =>
              `Dog(
                {
                  let value: DogFragment.Raw.t = Obj.magic(value);
                  DogFragment.verifyArgsAndParse(value);
                },
              )
            | _ => `FutureAddedValue(Obj.magic(value): Js.Json.t)
            }: t_dogOrHuman
          );
        },
      }: t
    );
    /**Serialize the ReasonML GraphQL data that was parsed using the parse function back to the original JSON compatible data */
    let serialize = (value: t): Raw.t => (
      {
        let dogOrHuman = {
          let value = (value: t).dogOrHuman;
          switch (value) {
          | `Dog(value) => (
              Obj.magic(DogFragment.serialize(value)): Raw.t_dogOrHuman
            )
          | `FutureAddedValue(value) => (Obj.magic(value): Raw.t_dogOrHuman)
          };
        };
        {dogOrHuman: dogOrHuman};
      }: Raw.t
    );
    let makeVariables = () => ();
    let makeDefaultVariables = () => makeVariables();
    external unsafe_fromJson: Js.Json.t => Raw.t = "%identity";
    external toJson: Raw.t => Js.Json.t = "%identity";
    module Z__INTERNAL = {
      type root = t;
      type nonrec graphql_module;
      /****--- GraphQL PPX Module ---**

The contents of this module are automatically generated by `graphql-ppx`.
The following is simply an overview of the most important variables and types that you can access from this module.

```
module UnionExternalFragmentQuery {
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
};
