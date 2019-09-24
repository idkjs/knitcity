module CssBaseline = {
  [@react.component] [@bs.module "@material-ui/core"]
  external make: (~children: React.element) => React.element = "CssBaseline";
};

type useStyles = unit => unit;
[@bs.module "@material-ui/styles"]
external makeStyles: (Js.t({..}), Js.t({..})) => useStyles = "makeStyles";

let styles = {
  "@global": {
    "h1, h2, h3":
      ReactDOMRe.Style.make(~margin="0px", ~fontWeight="normal", ()),
    "ul": ReactDOMRe.Style.make(~margin="0", ~padding="0", ()),
    // "palette": ReactDOMRe.Style.make(
    //   ~colorPrimary="blue",
    //   ~colorSecondary="amber",
    //   ()),
  "typography":ReactDOMRe.Style.make(~fontFamily="Varela Round",
    ~useNextVariants=true,())
  },
};

let useStyles = makeStyles(styles, {"name": "App-default"});

[@bs.module] external bwRoses: string = "@/assets/BWroses.jpeg";
[@bs.module] external colorRoses: string = "@/assets/colorRoses.jpeg";
[@react.component]
let make = () => {
  useStyles();
  let url = ReasonReactRouter.useUrl();

  <React.Fragment>
    <CssBaseline>
      <Header />
      <Footer />
    </CssBaseline>
  </React.Fragment>;
};