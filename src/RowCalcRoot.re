module RowCalcParser = {
  type rowCalc = {
    title: string,
    rows: int,
  };
  type rows = array(rowCalc);
  let decodeRow = jsonString => {
    Json.Decode.{
      title: jsonString |> field("title", string),
      rows: jsonString |> field("rows", int),
    };
  };
  let decode = jsonString => Json.Decode.(jsonString |> array(decodeRow));

  let encodeRow = row => {
    Json.Encode.(
      object_([("title", string(row.title)), ("rows", int(row.rows))])
    );
  };
  let encode = (rows: array(rowCalc)) => {
    Json.Encode.(rows |> array(encodeRow));
  };
};
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
  let formControl =
    style([
      position(absolute),
      bottom(`percent(5.0)),
      right(`percent(50.0)),
      transform(translateX(`percent(50.0))),
    ]);
  let counterContainer =
    style([
      width(`percent(80.0)),
      overflowY(auto),
      height(`percent(60.0)),
    ]);
};
type state = {
  titleVal: string,
  rows: RowCalcParser.rows,
};
type actions =
  | AddNewRow
  | RemoveRow
  | Reset
  | UpdateRowIncrement(int)
  | ChangeText(string)
  | UpdateRowReset(int);

let initialState = {
    let jsonStringOpt = Dom.Storage.(localStorage |> getItem("rowCalcs"));

    let rows =
      switch (jsonStringOpt) {
      | Some(jsonString) =>
        switch (jsonString |> Json.parse) {
        | Some(json) => RowCalcParser.decode(json)
        | None => [||]
        }

      | None => [||]
      };
    {rows, titleVal: ""};
  };
  let reducer =(state, action) => {
    switch (action) {
    | AddNewRow =>
      let newRows: RowCalcParser.rows = [|{title: state.titleVal, rows: 0}|];
      {
        rows: Array.concat([state.rows, newRows]),
        titleVal: "",
      };
    | RemoveRow => state
    | Reset => {...state, rows: [||]}
    | UpdateRowIncrement(index) =>
      let newState = state;
      let toUpdate = newState.rows[index];
      newState.rows[index] = {title: toUpdate.title, rows: toUpdate.rows + 1};
      {newState};
    | UpdateRowReset(index) =>
      let newState = state;
      let toUpdate = newState.rows[index];
      newState.rows[index] = {title: toUpdate.title, rows: 0};
      newState;
    | ChangeText(toChange) =>
      {...state, titleVal: toChange}
    };
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  React.useEffect1(
    () => {
       Js.log(state.rows);
       Dom.Storage.(
         localStorage
         |> setItem(
              "rowCalcs",
              state.rows |> RowCalcParser.encode |> Json.stringify,
            )
       );
      None;
    },
    [|state|]
  );

    <>
      <div className={App.Styles.innerRoot ++ " " ++ Styles.counterContainer}>
        <MaterialUi.Grid direction=`Column alignItems=`Center container=true>
          {state.rows
           |> Array.mapi((index, a: RowCalcParser.rowCalc) =>
                <MaterialUi.Grid direction=`Column alignItems=`Center container=true  item=true key={string_of_int(index)}>
                  <RowCalc
                    rows={a.rows}
                    title={a.title}
                    index
                    newValues={action =>
                      switch (action) {
                      | Count(index) => dispatch(UpdateRowIncrement(index))
                      | Reset(index) => dispatch(UpdateRowReset(index))
                      }
                    }
                  />
                </MaterialUi.Grid>
              )
           |> ReasonReact.array}
        </MaterialUi.Grid>
      </div>
      <div className=Styles.formControl>
        <MaterialUi.Button onClick={_e => dispatch(AddNewRow)}>
          {ReasonReact.string("+ counter")}
        </MaterialUi.Button>
        <MaterialUi.Button onClick={_e => dispatch(Reset)}>
          {ReasonReact.string("Reset")}
        </MaterialUi.Button>
        <MaterialUi.TextField
          value=`String(state.titleVal)
          type_="text"
          fullWidth=false
          label={ReasonReact.string("Name")}
          onChange={e =>
            dispatch(ChangeText(ReactEvent.Form.target(e)##value))
          }
        />
      </div>
      <div
        className=Styles.floatingRightSideBack
        onClick={_e => ReasonReactRouter.push("/")}>
        <NavigationIcons.Back />
      </div>
    </>;
};