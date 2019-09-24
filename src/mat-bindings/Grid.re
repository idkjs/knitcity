[@bs.deriving jsConverter]
type alignContent = [
  | `stretch
  | `center
  | [@bs.as "flex-start"] `flexStart
  | [@bs.as "flex-end"] `flexEnd
  | [@bs.as "space-between"] `spaceBetween
  | [@bs.as "space-around"] `spaceAround
];

[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `flexStart
  | `center
  | [@bs.as "flex-end"] `flexEnd
  | `stretch
  | `baseline
];

[@bs.deriving jsConverter]
type direction = [
  | `row
  | [@bs.as "row-reverse"] `rowReverse
  | `column
  | [@bs.as "column-reverse"] `columnReverse
];

[@bs.deriving jsConverter]
type justify = [
  | [@bs.as "flex-start"] `flexStart
  | `center
  | [@bs.as "flex-end"] `flexEnd
  | [@bs.as "space-between"] `spaceBetween
  | [@bs.as "space-around"] `spaceAround
  | [@bs.as "space-evenly"] `spaceEvenly
];

// [@bs.deriving abstract]
// type jsProps = {
//   alignContent: string,
//   alignItems: string,
//   direction: string,
//   justify: string,
//   spacing: int,
//   container: bool,
// };
[@bs.deriving jsConverter]
type spacing =
  | Zero
  | [@bs.as 1] One
  | [@bs.as 2] Two
  | [@bs.as 3] Three;
[@bs.module "@material-ui/core/Grid/Grid"]
external make:
  (
    ~alignContent: [@bs.string] [
                     | `stretch
                     | `center
                     | [@bs.as "flex-start"] `flexStart
                     | [@bs.as "flex-end"] `flexEnd
                     | [@bs.as "space-between"] `spaceBetween
                     | [@bs.as "space-around"] `spaceAround
                   ],
    ~alignItems: [@bs.string] [
                   | [@bs.as "flex-start"] `flexStart
                   | `center
                   | [@bs.as "flex-end"] `flexEnd
                   | `stretch
                   | `baseline
                 ],
    ~direction: [@bs.string] [
                  | `row
                  | [@bs.as "row-reverse"] `rowReverse
                  | `column
                  | [@bs.as "column-reverse"] `columnReverse
                ],
    ~justify: [@bs.string] [
                | [@bs.as "flex-start"] `flexStart
                | `center
                | [@bs.as "flex-end"] `flexEnd
                | [@bs.as "space-between"] `spaceBetween
                | [@bs.as "space-around"] `spaceAround
                | [@bs.as "space-evenly"] `spaceEvenly
              ],
    ~spacing: spacing,
    ~children: React.element,
    unit
  ) =>
  React.element =
  "Grid";

module Item = {
  [@react.component]
  let make = (~ml: Js.nullable(int), ~item=true, ~children) => children;
};