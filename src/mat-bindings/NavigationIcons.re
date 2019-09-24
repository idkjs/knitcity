module Forward = {
  [@bs.module "@material-ui/icons/ArrowForwardRounded"] [@react.component]
  external make: unit => React.element = "default";
};

module Back = {
  [@bs.module "@material-ui/icons/ArrowBackRounded"] [@react.component]
  external make: unit => React.element = "default";
};