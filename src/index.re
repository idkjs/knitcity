module Root = {
  [@react.component]
  let make = () => {
    <React.Fragment>
      <ThemeProvider>
        <MaterialUi.CssBaseline> <App /> </MaterialUi.CssBaseline>
      </ThemeProvider>
    </React.Fragment>;
  };
};
ReactDOMRe.renderToElementWithId(<BGW />, "root");
