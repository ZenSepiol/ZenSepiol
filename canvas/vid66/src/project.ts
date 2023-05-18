import {makeProject} from '@motion-canvas/core';

import one from './scenes/one?scene';
import two from './scenes/two?scene';

export default makeProject({
  scenes: [one,two],
});
