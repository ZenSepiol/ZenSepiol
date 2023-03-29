import {makeScene2D} from '@motion-canvas/2d/lib/scenes';
import {createRef} from '@motion-canvas/core/lib/utils';
import {
  CodeBlock,
  edit,
  insert,
  lines,
  remove,
} from '@motion-canvas/2d/lib/components/CodeBlock';
import {all, waitFor} from '@motion-canvas/core/lib/flow';

export default makeScene2D(function* (view) {
  view.fill('#1B1D20'); // set the background of this scene

  const codeRef = createRef<CodeBlock>();

  yield view.add(<CodeBlock scale={[0.8, 0.8]} language="tex" ref={codeRef} code={``} />);

  const time = 0.04
  // const sentence = " \
  //     Use consistent naming conventions for variables and functions.\n \
  // For example, some variables use snake_case while others use camelCase.\n \
  //     It is better to stick to one convention throughout the code.";

  // const sentence = " \
  //     Avoid using magic numbers in the code. Instead, define constants or \n \
  // variables with descriptive names. For example, instead of using 3 directly \n \
  //       in the loops, define a constant like const int BOARD_SIZE = 3.";

  // const sentence = " \
  //     Separate the game logic from the user interface. The DrawCell \n \
  //  function currently contains both the game logic and the drawing code.\n \
  //     It is better to separate these concerns into different functions.";

  // const sentence = " \
  //         Add comments to explain the code. \n \
  //  Some parts of the code are not immediately obvious,\n \
  // and adding comments can make it easier to understand.";

  const sentence = " \
      Use const whenever possible to indicate that a \n \
  variable or function argument is not meant to be modified.";

  // const sentence = " \
  // Use range-based loops instead of traditional for-loops when iterating \n \
  // over containers. For example, instead of for (int i = 0; i < 3; ++i), \n \
  //               use for (auto& row : game_state).";

  const words = sentence.split("");
  let typed_sentence = "";

  for (let i = 0; i < words.length; i++) {
    yield* codeRef().edit(time, false)`${typed_sentence}${insert(words[i])}`;
    typed_sentence += words[i];
  }

  yield* waitFor(2.0);

  // yield* waitFor(0.6);
  // yield* codeRef().edit(1.2)`var myBool = ${edit('true', 'false')};`;
  // yield* waitFor(0.6);
  // yield* all(
  //   codeRef().selection(lines(0, Infinity), 1.2),
  //   codeRef().edit(1.2, false)`var my${edit('Bool', 'Number')} = ${edit(
  //     'false',
  //     '42',
  //   )};`,
  // );
  // yield* waitFor(0.6);
  // yield* codeRef().edit(1.2, false)`var myNumber${remove(' = 42')};`;
  // yield* waitFor(0.6);
  // yield* codeRef().edit(1.2, false)`var my${edit('Number', 'Bool')};`;
  // yield* waitFor(0.6);
});
