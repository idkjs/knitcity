// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var ReactDOMRe = require("reason-react/src/ReactDOMRe.js");
var Caml_option = require("bs-platform/lib/js/caml_option.js");
var App$KnitZilla = require("./App.bs.js");
var Core = require("@material-ui/core");
var MaterialUi_CssBaseline = require("@jsiebern/bs-material-ui/src/MaterialUi_CssBaseline.bs.js");
var ThemeProvider$KnitZilla = require("./ThemeProvider.bs.js");
var BackgroundWrapper$KnitZilla = require("./BackgroundWrapper.bs.js");

function Index$Root(Props) {
  return React.createElement(React.Fragment, {
              children: React.createElement(ThemeProvider$KnitZilla.make, {
                    children: React.createElement(Core.CssBaseline, MaterialUi_CssBaseline.makeProps(Caml_option.some(React.createElement(App$KnitZilla.make, { })), undefined, undefined, /* () */0))
                  })
            });
}

var Root = /* module */[/* make */Index$Root];

ReactDOMRe.renderToElementWithId(React.createElement(BackgroundWrapper$KnitZilla.make, { }), "root");

exports.Root = Root;
/*  Not a pure module */
