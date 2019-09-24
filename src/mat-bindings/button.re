type onClick = ReactEvent.Mouse.t => unit;
[@bs.deriving jsConverter]
type variant = [ | `text | `outlined | `contained | `fab | `extendedFab];

[@bs.deriving jsConverter]
type color = [ | `primary | `secondary];

[@bs.module "@material-ui/core/Button/Button"][@react.component]
external button:(~variant: option(variant), ~color: option(color), ~onClick: onClick, ~children:'a, unit) => React.element = "default";


module IconButton = {
  [@bs.module "@material-ui/core/IconButton/IconButton"][@react.component]
  external button:(~onClick: onClick, ~className: string=?, ~children:'a, unit) => React.element = "default";
};