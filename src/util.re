let calculateMasks = (~currentMasks, ~masksToInsertOrRemove) => {
  switch (currentMasks, masksToInsertOrRemove) {
  | (0, _) => [||]
  | (_, 0) => [||]
  | (_, _) when masksToInsertOrRemove > currentMasks => [||]
  | (_, _) =>
    let temp =
      float_of_int(currentMasks) /. float_of_int(masksToInsertOrRemove);
    let floored = floor(temp);
    let ceiled = ceil(temp);
    let diff = temp -. floored;
    switch (diff) {
    | _ when diff > 0.85 => [|ceiled|]
    | _ when diff < 0.15 => [|floored|]
    | _ when diff == 0. => [|temp|]
    | _ => [|floored, ceiled|]
    };
  };
};

module Result = {
  [@react.component]
  let make = (~results) => {
    let listLength = Array.length(results);
    switch (listLength) {
    | 0 =>
      <MaterialUi_Typography align=`Center>
        {ReasonReact.string("Intet at udregne endnu")}
      </MaterialUi_Typography>
    | 1 =>
      let result = results[0];
      <MaterialUi_Typography align=`Center>
        {ReasonReact.string({j| Strik 1 maske ind pr $result maske(r) |j})}
      </MaterialUi_Typography>;
    | _ =>
      results
      |> Array.mapi((index, result) =>
           <MaterialUi_Typography align=`Center key={string_of_int(index)}>
             {ReasonReact.string(
                {j| strik 1 maske ind pr $result maske(r) |j},
              )}
           </MaterialUi_Typography>
         )
      |> ReasonReact.array
    };
  };
};