module Styles = {
  open Css;
  let floatingRightSideBack =
    style([position(absolute), top(`percent(50.0)), left(px(5))]);
  let numberWrapper =
    style([
      border(px(1), solid, rgba(0, 0, 0, 0.87)),
      borderRadius(px(5)),
      padding2(~v=px(12), ~h=px(24)),
    ]);
};
type updateActions =
  | Count(int)
  | Reset(int);
let rs = React.string;
[@react.component]
let make = (~rows, ~title, ~newValues: updateActions => unit, ~index) => {
  <>
    <MaterialUi_Typography align=`Center variant=`Body1>
      title->rs
    </MaterialUi_Typography>
    <MaterialUi.Grid direction=`Column alignItems=`Center container=true>
      <MaterialUi.Grid
        direction=`Column item=true alignItems=`Center container=true>
        <div
          onClick={_e => newValues(Count(index))}
          className=Styles.numberWrapper>
          <MaterialUi_Typography variant=`H6>
            {React.string(string_of_int(rows))}
          </MaterialUi_Typography>
        </div>
      </MaterialUi.Grid>
      <MaterialUi.Grid
        direction=`Column item=true alignItems=`Center container=true>
        <MaterialUi.Grid direction=`Column alignItems=`Center container=true>
          <MaterialUi.Grid
            direction=`Column item=true alignItems=`Center container=true>
            <MaterialUi.Button
              variant=`Text
              onClick={_e => {
                Js.log2("newValues(Count(index))", index);
                newValues(Count(index));
              }}>
              {React.string("+1")}
            </MaterialUi.Button>
          </MaterialUi.Grid>
          <MaterialUi.Grid
            direction=`Column item=true alignItems=`Center container=true>
            <MaterialUi.Button
              variant=`Text onClick={_e => newValues(Reset(index))}>
              {React.string("Reset")}
            </MaterialUi.Button>
          </MaterialUi.Grid>
        </MaterialUi.Grid>
      </MaterialUi.Grid>
    </MaterialUi.Grid>
  </>;
};