external styleToString: ReactDOMRe.Style.t => string = "%identity";
let theme =
  MaterialUi_Theme.create(
    MaterialUi_ThemeOptions.(
      make(
        ~palette=
          PaletteOptions.make(
            ~primary=Primary.make(~main=MaterialUi_Color_Amber.c100, ()),
            ~secondary=Secondary.make(~main=MaterialUi_Color_Blue.c100, ()),
            (),
          ),
        ~typography=Typography.make(~fontFamily="Varela Round", ()),
        (),
      )
    ),
  );


[@react.component]
let make = (~children) =>
  MaterialUi.(<MuiThemeProvider theme> children </MuiThemeProvider>);