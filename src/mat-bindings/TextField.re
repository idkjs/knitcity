// [@bs.deriving abstract]
// type jsProps = {
//   variant: string,
//   [@bs.as "type"]
//   type_: string,
//   value: string,
//   label: ReasonReact.reactElement,
//   fullWidth: bool,
//   onChange: ReactEvent.Form.t => unit,
//   disabled: Js.nullable(bool),
// };

[@bs.deriving jsConverter]
type variant = [ | `standard | `outlined | `filled];

[@bs.deriving jsConverter]
type type_ = [ | `number | `email | `text];
// [@bs.module "@material-ui/core/TextField/TextField"][@react.component]
// external textField:(
//       ~value:value,
//       // ~fullWidth,
//       // ~onChange,
//       // ~label,
//       // ~type_,
//       // ~variant:`standard,
//       ~disabled: Js.Nullable.fromOption(bool),
//       ~children:'a,
//       unit
//     ) => React.element = "default";

[@bs.module "@material-ui/core"] [@react.component]
external make:
  (
    ~disabled: bool=?,
    ~className: string=?,
    ~autoFocus: bool=?,
    ~_type: option(type_),
    ~style: ReactDOMRe.Style.t=?,
    ~variant: option(variant),
    ~value: string=?,
    ~placeholder: string=?,
    ~label: string=?,
    ~onChange: 'a=?,
    ~inputProps: Js.t({..})=?,
    ~children: React.element=?,
    unit
  ) =>
  React.element =
  "TextField";