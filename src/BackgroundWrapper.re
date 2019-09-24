[@bs.val]
external addEventListener: (string, ReactEvent.Touch.t => unit) => unit =
  "window.addEventListener";
module Styles = {
  open Css;
  let root =
    style([
      height(`percent(100.0)),
      width(`percent(100.0)),
      position(`absolute),
      backgroundImage(
        linearGradient(
          grad(0.0),
          [(px(0), `hex("A5A6C5")), (px(100), `hex("F8DFC9"))],
        ),
      ),
    ]);
};

type routes =
  | Home
  | Calc;

type state = {
  activeRoute: routes,
  startClientX: int,
};

type actions =
  | Route(routes)
  | TouchStart(int);

type direction =
  | Left
  | Right;
let reducer = (state, action) => {
  switch (action) {
  | Route(toChange) => {...state, activeRoute: toChange}
  | TouchStart(startX) => {...state, startClientX: startX}
  };
};
let initialState = {activeRoute: Home, startClientX: 0};
let x = ref(0);
[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let useAppUrl = () => {
    let url = ReasonReactRouter.useUrl();

    switch (url.path) {
    | ["calc"] => dispatch(Route(Calc))
    | _ => dispatch(Route(Home))
    };
  };
  React.useEffect1(
    () => {
      let touchListen =
        ReasonReact.Router.watchUrl(url =>
          switch (url.path) {
          | ["calc"] => dispatch(Route(Calc))
          | _ => dispatch(Route(Home))
          }
        );

      addEventListener("touchstart", e => {
        let touch =
          ReactEvent.Touch.touches(e)
          ->TouchEvent.Touch.castReactTouchListToTouchArray
          ->(Array.get(0));
        let touchVal = touch##clientX;
        x := touchVal;
      });
      addEventListener("touchend", e => {
        let touch =
          ReactEvent.Touch.changedTouches(e)
          ->TouchEvent.Touch.castReactTouchListToTouchArray
          ->(Array.get(0));
        let totalWindowWidth =
          float_of_int(touch##target->Webapi.Dom.Element.clientWidth);
        let screenChange = x^ - touch##clientX;
        let minReqMovement = totalWindowWidth *. 0.25;
        let dir = screenChange > 0 ? Left : Right;
        if (abs(screenChange) > int_of_float(minReqMovement)) {
          switch (dir) {
          | Left => ReasonReactRouter.push("/calc")
          | Right => ReasonReactRouter.push("/")
          };
        };
        x := 0;
      });
      // None;
      Some(() => ReasonReactRouter.unwatchUrl(touchListen));
    },
    [|state|],
  );

  <div className=Styles.root>
    <App.Header />
    {switch (state.activeRoute) {
     | Home => <App />
     | Calc => <RowCalcRoot />
     }}
  </div>;
};
let default = make;