module Header = {
  module Style = {
    open Css;
    let headerStyle =
      style([
        position(absolute),
        top(px(25)),
        width(`percent(100.0)),
        color(hex("fff")),
      ]);
  };
  [@react.component]
  let make = () => {
    <MaterialUi_Typography className=Style.headerStyle variant=`H3>
      "KnitZilla"->React.string
    </MaterialUi_Typography>;
  };
};
module Styles = {
  open Css;
  let innerRoot =
    style([
      padding(px(16)),
      position(absolute),
      top(`percent(50.0)),
      left(`percent(50.0)),
      transform(translate(`percent(-50.0), `percent(-50.0))),
    ]);
  let floatingNextButton =
    style([position(absolute), top(`percent(50.0)), right(px(5))]);
};

type state = {
  currentMasks: int,
  masksToInsert: int,
};

type action =
  | SetCurrentMasks(int)
  | SetMasksToInsert(int);

let nanTest = toTest => {
  let nanTest = compare(float_of_int(toTest), nan);

  switch (nanTest) {
  | 0 => 0
  | _ => toTest
  };
};
let initialState = {currentMasks: 0, masksToInsert: 0};
let reducer = (state, action) =>
  switch (action) {
  | SetCurrentMasks(toSet) => {...state, currentMasks: nanTest(toSet)}
  | SetMasksToInsert(toSet) => {...state, masksToInsert: nanTest(toSet)}
  };
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

  <>
    <div className=Styles.innerRoot>
      <MaterialUi.Grid spacing=V3 direction=`Column alignItems=`Center justify=`Center>
        <MaterialUi.Grid item=true>
          <MaterialUi.TextField
            variant=`Outlined
            label={ReasonReact.string("Antal masker")}
            fullWidth=true
            value={
              state.currentMasks === 0
                ? `String("") : `Int(state.currentMasks)
            }
            type_="number"
            onChange={e =>
              dispatch(
                SetCurrentMasks(ReactEvent.Form.target(e)##valueAsNumber),
              )
            }
          />
        </MaterialUi.Grid>
        <MaterialUi.Grid item=true>
          <MaterialUi.TextField
            variant=`Outlined
            label={ReasonReact.string({js|Indsæt|js})}
            type_="number"
            fullWidth=true
            value={
              state.masksToInsert === 0
                ? `String("")  : `Int(state.masksToInsert)
            }
            onChange={e =>
              dispatch(
                SetMasksToInsert(ReactEvent.Form.target(e)##valueAsNumber),
              )
            }
          />
        </MaterialUi.Grid>
        <MaterialUi.Grid item=true>
          <Util.Result
            results={Util.calculateMasks(
              ~currentMasks=state.currentMasks,
              ~masksToInsertOrRemove=state.masksToInsert,
            )}
          />
        </MaterialUi.Grid>
      </MaterialUi.Grid>
    </div>
    <div
      className=Styles.floatingNextButton
      onClick={_e => ReasonReactRouter.push("/calc")}>
      <NavigationIcons.Forward />
    </div>
  </>;
};