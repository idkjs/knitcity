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

[@react.component]
let make = () => {
  let route = Routing.useAppUrl();

  let activeRoute =
    React.useMemo1(
      () =>
        switch (route) {
        | Home => <App />
        | Calc => <RowCalcRoot />
        },
      [|route|],
    );

    <div className=Styles.root>
    <App.Header />
   activeRoute
  </div>;
};
