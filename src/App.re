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
      <Typography className=Style.headerStyle variant=`h3>
        {ReasonReact.string("KnitZilla")}
      </Typography>;
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
    | SetCurrentMasks(toSet) =>
      ReasonReact.Update({...state, currentMasks: nanTest(toSet)})
    | SetMasksToInsert(toSet) =>
      ReasonReact.Update({...state, masksToInsert: nanTest(toSet)})
    };
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);

    <>
      <div className=Styles.innerRoot>
        <Grid
          spacing=Three direction=`column alignItems=`center justify=`center>
          <Grid.Item>
            <TextField
              variant=`outlined
              label={ReasonReact.string("Antal masker")}
              fullWidth=true
              value={
                state.currentMasks === 0
                  ? "" : string_of_int(state.currentMasks)
              }
              type_=`number
              onChange={e =>
                dispatch(
                  SetCurrentMasks(ReactEvent.Form.target(e)##valueAsNumber),
                )
              }
            />
          </Grid.Item>
          <Grid.Item>
            <TextField
              variant=`outlined
              label={ReasonReact.string({js|Indsæt|js})}
              type_=`number
              fullWidth=true
              value={
                state.masksToInsert === 0
                  ? "" : string_of_int(state.masksToInsert)
              }
              onChange={e =>
                dispatch(
                  SetMasksToInsert(ReactEvent.Form.target(e)##valueAsNumber),
                )
              }
            />
          </Grid.Item>
          <Grid.Item>
            <Util.Result
              results={Util.calculateMasks(
                ~currentMasks=state.currentMasks,
                ~masksToInsertOrRemove=state.masksToInsert,
              )}
            />
          </Grid.Item>
        </Grid>
      </div>
      <div
        className=Styles.floatingNextButton
        onClick={_e => ReasonReact.Router.push("/calc")}>
        <NavigationIcons.Forward />
      </div>
    </>;
};
