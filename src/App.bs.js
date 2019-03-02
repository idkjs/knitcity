// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Caml_primitive = require("bs-platform/lib/js/caml_primitive.js");
var Grid$KnitZilla = require("./mat-bindings/Grid.bs.js");
var Util$KnitZilla = require("./util.bs.js");
var TextField$KnitZilla = require("./mat-bindings/TextField.bs.js");
var Typography$KnitZilla = require("./mat-bindings/Typography.bs.js");
var NavigationIcons$KnitZilla = require("./mat-bindings/NavigationIcons.bs.js");

var headerStyle = Css.style(/* :: */[
      Css.position(Css.absolute),
      /* :: */[
        Css.top(Css.px(25)),
        /* :: */[
          Css.width(/* `percent */[
                -119887163,
                100.0
              ]),
          /* :: */[
            Css.color(Css.hsl(28, 100, 94)),
            /* [] */0
          ]
        ]
      ]
    ]);

var Style = /* module */[/* headerStyle */headerStyle];

var component = ReasonReact.statelessComponent("Header");

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return ReasonReact.element(undefined, undefined, Typography$KnitZilla.make(/* h3 */23243, undefined, headerStyle, /* array */["KnitZilla"]));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var Header = /* module */[
  /* Style */Style,
  /* component */component,
  /* make */make
];

var innerRoot = Css.style(/* :: */[
      Css.padding(Css.px(16)),
      /* :: */[
        Css.position(Css.absolute),
        /* :: */[
          Css.top(/* `percent */[
                -119887163,
                50.0
              ]),
          /* :: */[
            Css.left(/* `percent */[
                  -119887163,
                  50.0
                ]),
            /* :: */[
              Css.transform(Css.translate(/* `percent */[
                        -119887163,
                        -50.0
                      ], /* `percent */[
                        -119887163,
                        -50.0
                      ])),
              /* [] */0
            ]
          ]
        ]
      ]
    ]);

var floatingNextButton = Css.style(/* :: */[
      Css.position(Css.absolute),
      /* :: */[
        Css.top(/* `percent */[
              -119887163,
              50.0
            ]),
        /* :: */[
          Css.right(Css.px(5)),
          /* [] */0
        ]
      ]
    ]);

var Styles = /* module */[
  /* innerRoot */innerRoot,
  /* floatingNextButton */floatingNextButton
];

var component$1 = ReasonReact.reducerComponent("AppRoot");

function nanTest(toTest) {
  var nanTest$1 = Caml_primitive.caml_float_compare(toTest, Number.NaN);
  if (nanTest$1 !== 0) {
    return toTest;
  } else {
    return 0;
  }
}

function make$1(_children) {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* currentMasks */0] === 0;
              var match$1 = self[/* state */1][/* masksToInsert */1] === 0;
              return React.createElement(React.Fragment, undefined, React.createElement("div", {
                              className: innerRoot
                            }, ReasonReact.element(undefined, undefined, Grid$KnitZilla.make(undefined, /* center */98248149, /* column */-963948842, /* center */98248149, /* Sixteen */2, /* array */[
                                      ReasonReact.element(undefined, undefined, Grid$KnitZilla.Item[/* make */0](undefined, /* array */[ReasonReact.element(undefined, undefined, TextField$KnitZilla.make(match ? "" : String(self[/* state */1][/* currentMasks */0]), true, (function (e) {
                                                            return Curry._1(self[/* send */3], /* SetCurrentMasks */Block.__(0, [e.target.valueAsNumber]));
                                                          }), "Antal masker", /* number */561678025, /* outlined */613841570, undefined, /* array */[]))])),
                                      ReasonReact.element(undefined, undefined, Grid$KnitZilla.Item[/* make */0](undefined, /* array */[ReasonReact.element(undefined, undefined, TextField$KnitZilla.make(match$1 ? "" : String(self[/* state */1][/* masksToInsert */1]), true, (function (e) {
                                                            return Curry._1(self[/* send */3], /* SetMasksToInsert */Block.__(1, [e.target.valueAsNumber]));
                                                          }), "Indsæt", /* number */561678025, /* outlined */613841570, undefined, /* array */[]))])),
                                      ReasonReact.element(undefined, undefined, Grid$KnitZilla.Item[/* make */0](undefined, /* array */[ReasonReact.element(undefined, undefined, Util$KnitZilla.Result[/* make */1](Util$KnitZilla.calculateMasks(self[/* state */1][/* currentMasks */0], self[/* state */1][/* masksToInsert */1]), /* array */[]))]))
                                    ]))), React.createElement("div", {
                              className: floatingNextButton,
                              onClick: (function (_e) {
                                  return ReasonReact.Router[/* push */0]("/calc");
                                })
                            }, ReasonReact.element(undefined, undefined, NavigationIcons$KnitZilla.Forward[/* make */0](undefined, /* array */[]))));
            }),
          /* initialState */(function (param) {
              return /* record */[
                      /* currentMasks */0,
                      /* masksToInsert */0
                    ];
            }),
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */(function (action, state) {
              if (action.tag) {
                return /* Update */Block.__(0, [/* record */[
                            /* currentMasks */state[/* currentMasks */0],
                            /* masksToInsert */nanTest(action[0])
                          ]]);
              } else {
                return /* Update */Block.__(0, [/* record */[
                            /* currentMasks */nanTest(action[0]),
                            /* masksToInsert */state[/* masksToInsert */1]
                          ]]);
              }
            }),
          /* jsElementWrapped */component$1[/* jsElementWrapped */13]
        ];
}

exports.Header = Header;
exports.Styles = Styles;
exports.component = component$1;
exports.nanTest = nanTest;
exports.make = make$1;
/* headerStyle Not a pure module */
