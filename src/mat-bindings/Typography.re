// [@bs.module "@material-ui/core/Typography/Typography"]
// external typography: React.element = "default";

// type align = [@bs.string][ | `center];

// type variant = [@bs.string][ | `h3 | `body1 | `h6];

// [@bs.deriving abstract]
// type jsProps = {
//   variant: string,
//   align: string,
//   className: Js.nullable(string),
// };

// let make = (~variant=`body1, ~align=`center, ~className=?, children) =>
//   ReasonReact.wrapJsForReason(
//     ~reactClass=typography,
//     ~props=
//       jsProps(
//         ~className=className |> Js.Nullable.fromOption,
//         ~variant=variant |> variantToJs,
//         ~align=align |> alignToJs,
//       ),
//     children,
//   );

  [@bs.module "@material-ui/core"] [@react.component]
  external make:
    (
      ~variant: [@bs.string][ | `h3 | `body1 | `h6]=?,
      ~className: string=?,
      ~align: [@bs.string][ | `center],
      ~children: React.element,
      unit
    ) =>
    React.element =
    "Typography";