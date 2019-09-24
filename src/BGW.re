[@bs.val]
external addEventListener:
  ([@bs.string] [ | `touchstart | `touchend], ReactEvent.Touch.t => unit) =>
  unit =
  "window.addEventListener";

// [@bs.val]
// external addEventListener:
//   ([@bs.string] [ | `url], {. "url": string} => unit) => unit =
//   "";

[@bs.val]
external removeEventListener:
  ([@bs.string] [ | `touchstart | `touchend], {. "url": string} => unit) => unit =
  "window.removeEventListener";

type state = {
  activeRoute: Routing.routes,
  startClientX: int,
};

type actions =
  | Route(Routing.routes)
  | TouchStart(int);

type direction =
  | Left
  | Right;

let x = ref(0);
[@react.component]
let make = (~activeRoute=Routing.useAppUrl()) => {

    let (_state, dispatch) =
      React.useReducer(
        (state, action) =>
          switch (action) {
          | TouchStart(startX) =>
            {...state, startClientX: startX}
            | Route(route) => {...state, activeRoute: route};
          },
            {activeRoute: Home, startClientX: 0}
      );
      let onTouchStart = e => {
        let touch =
          ReactEvent.Touch.touches(e)
          ->TouchEvent.Touch.castReactTouchListToTouchArray
          ->(Array.get(0));
        let touchVal = touch##clientX;
        x := touchVal;
        dispatch(TouchStart(x^))
      };
        let onTouchEnd = e => {
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
        };
React.useEffect(() => {
  // let touchListen = Routing.useAppUrl();
// let watcherId = Routing.useAppUrl();
  dispatch(Route(activeRoute))
  addEventListener(`touchstart, e => onTouchStart(e));

  addEventListener(`touchend, e => onTouchEnd(e));
  Some(() => {
    let _ = removeEventListener(`touchstart);

    let _ = removeEventListener(`touchend);

    })
});
  <>
     <Root />
  </>;
};