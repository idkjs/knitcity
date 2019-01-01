// Generated by BUCKLESCRIPT VERSION 4.0.14, PLEASE EDIT WITH CARE
'use strict';

var Js_mapperRt = require("bs-platform/lib/js/js_mapperRt.js");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Js_null_undefined = require("bs-platform/lib/js/js_null_undefined.js");
var Typography = require("@material-ui/core/Typography/Typography");

var jsMapperConstantArray = /* array */[/* tuple */[
    98248149,
    "center"
  ]];

function alignToJs(param) {
  return Js_mapperRt.binarySearch(1, param, jsMapperConstantArray);
}

function alignFromJs(param) {
  return Js_mapperRt.revSearch(1, jsMapperConstantArray, param);
}

var jsMapperConstantArray$1 = /* array */[
  /* tuple */[
    23243,
    "h3"
  ],
  /* tuple */[
    23246,
    "h6"
  ],
  /* tuple */[
    921686863,
    "body1"
  ]
];

function variantToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray$1);
}

function variantFromJs(param) {
  return Js_mapperRt.revSearch(3, jsMapperConstantArray$1, param);
}

function make($staropt$star, $staropt$star$1, className, children) {
  var variant = $staropt$star !== undefined ? $staropt$star : /* body1 */921686863;
  var align = $staropt$star$1 !== undefined ? $staropt$star$1 : /* center */98248149;
  return ReasonReact.wrapJsForReason(Typography.default, {
              variant: variantToJs(variant),
              align: alignToJs(align),
              className: Js_null_undefined.fromOption(className)
            }, children);
}

exports.alignToJs = alignToJs;
exports.alignFromJs = alignFromJs;
exports.variantToJs = variantToJs;
exports.variantFromJs = variantFromJs;
exports.make = make;
/* ReasonReact Not a pure module */
