module Forward = {
  [@bs.module "@material-ui/icons/ArrowForwardRounded"] [@react.component]
  external make: (~className:option(string),unit) => React.element = "default";
  // [@bs.module "@material-ui/icons/ArrowForwardRounded"]
  // external next: React.element = "default";

  // [@bs.deriving abstract]
  // type jsProps = {className: Js.nullable(string)};

  // let make = (~className=?, children) =>
  //   ReasonReact.wrapJsForReason(
  //     ~reactClass=next,
  //     ~props=jsProps(~className=className |> Js.Nullable.fromOption),
  //     children,
  //   );
};

module Back = {
    [@bs.module "@material-ui/icons/ArrowBackRounded"] [@react.component]
    external make: (~className: option(string), unit) => React.element =
      "default";
  // [@bs.module "@material-ui/icons/ArrowBackRounded"]
  // external next: React.element = "default";

  // [@bs.deriving abstract]
  // type jsProps = {className: Js.nullable(string)};

  // let make = (~className=?, children) =>
  //   ReasonReact.wrapJsForReason(
  //     ~reactClass=next,
  //     ~props=jsProps(~className=className |> Js.Nullable.fromOption),
  //     children,
  //   );
};