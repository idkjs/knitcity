// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -485895757,
    "space-around"
  ],
  /* tuple */[
    -162316795,
    "stretch"
  ],
  /* tuple */[
    98248149,
    "center"
  ],
  /* tuple */[
    516682146,
    "space-between"
  ],
  /* tuple */[
    662439529,
    "flex-start"
  ],
  /* tuple */[
    924268066,
    "flex-end"
  ]
];

function alignContentToJs(param) {
  return Js_mapperRt.binarySearch(6, param, jsMapperConstantArray);
}

function alignContentFromJs(param) {
  return Js_mapperRt.revSearch(6, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    -162316795,
    "stretch"
  ],
  /* tuple */[
    98248149,
    "center"
  ],
  /* tuple */[
    287825029,
    "baseline"
  ],
  /* tuple */[
    662439529,
    "flex-start"
  ],
  /* tuple */[
    924268066,
    "flex-end"
  ]
];

function alignItemsToJs(param) {
  return Js_mapperRt.binarySearch(5, param, jsMapperConstantArray$1);
}

function alignItemsFromJs(param) {
  return Js_mapperRt.revSearch(5, jsMapperConstantArray$1, param);
}

var jsMapperConstantArray$2 = /* array */[
  /* tuple */[
    -963948842,
    "column"
  ],
  /* tuple */[
    5693978,
    "row"
  ],
  /* tuple */[
    135477484,
    "column-reverse"
  ],
  /* tuple */[
    378951208,
    "row-reverse"
  ]
];

function directionToJs(param) {
  return Js_mapperRt.binarySearch(4, param, jsMapperConstantArray$2);
}

function directionFromJs(param) {
  return Js_mapperRt.revSearch(4, jsMapperConstantArray$2, param);
}

var jsMapperConstantArray$3 = /* array */[
  /* tuple */[
    -1016061555,
    "space-evenly"
  ],
  /* tuple */[
    -485895757,
    "space-around"
  ],
  /* tuple */[
    98248149,
    "center"
  ],
  /* tuple */[
    516682146,
    "space-between"
  ],
  /* tuple */[
    662439529,
    "flex-start"
  ],
  /* tuple */[
    924268066,
    "flex-end"
  ]
];

function justifyToJs(param) {
  return Js_mapperRt.binarySearch(6, param, jsMapperConstantArray$3);
}

function justifyFromJs(param) {
  return Js_mapperRt.revSearch(6, jsMapperConstantArray$3, param);
}

function spacingToJs(param) {
  return param + 0 | 0;
}

function spacingFromJs(param) {
  if (param <= 3 && 0 <= param) {
    return param - 0 | 0;
  }
  
}

function Grid$Item(Props) {
  Props.ml;
  Props.item;
  return Props.children;
}

var Item = /* module */[/* make */Grid$Item];

exports.alignContentToJs = alignContentToJs;
exports.alignContentFromJs = alignContentFromJs;
exports.alignItemsToJs = alignItemsToJs;
exports.alignItemsFromJs = alignItemsFromJs;
exports.directionToJs = directionToJs;
exports.directionFromJs = directionFromJs;
exports.justifyToJs = justifyToJs;
exports.justifyFromJs = justifyFromJs;
exports.spacingToJs = spacingToJs;
exports.spacingFromJs = spacingFromJs;
exports.Item = Item;
/* No side effect */
