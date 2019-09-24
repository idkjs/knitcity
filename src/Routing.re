type routes =
  | Home
  | Calc;

let routeToPath = route =>
  switch (route) {
  | Home => "home"
  | Calc => "calc"
  };

let routeToUrl = route =>
  switch (route) {
  | Home => "/"
  | Calc => "/calc"
  };

let useAppUrl = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | ["calc"] => Calc
  | ["home"]
  | [] => Home
  | _ => Home
  };
};
