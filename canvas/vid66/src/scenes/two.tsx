import {makeScene2D} from '@motion-canvas/2d';
import {all, waitFor, waitUntil} from '@motion-canvas/core/lib/flow';
import {Layout, Rect, Txt, Line, Circle} from '@motion-canvas/2d/lib/components';
import {createRef, makeRef, useScene} from '@motion-canvas/core/lib/utils';
import {map} from '@motion-canvas/core/lib/tweening';
import {createSignal} from '@motion-canvas/core/lib/signals';
import {Direction, Spacing, Vector2} from '@motion-canvas/core/lib/types';
import {slideTransition} from '@motion-canvas/core/lib/transitions';

export default makeScene2D(function* (view) {
  view.fill('#1B1D20'); // set the background of this scene
  
  const task_5 = createRef<Circle>();
  const task_1 = createRef<Circle>();
  const task_2 = createRef<Circle>();
  const task_3 = createRef<Circle>();
  const task_4 = createRef<Circle>();
  const thread_1 = createRef<Circle>();
  const thread_2 = createRef<Circle>();
  const thread_3 = createRef<Circle>();

  view.add(
    <>
      <Circle          
          lineWidth={5}
          width={150}
          height={150}
          fill={'#177BA6'}
          ref={task_1}
          y={-150}
          x={-1200}
        />
              <Circle          
          lineWidth={5}
          width={150}
          height={150}
          fill={'#177BA6'}
          ref={task_2}
          y={-150}
          x={-1200}
        />
              <Circle          
          lineWidth={5}
          width={150}
          height={150}
          fill={'#177BA6'}
          ref={task_3}
          y={-150}
          x={-1200}
        />
              <Circle          
          lineWidth={5}
          width={150}
          height={150}
          fill={'#177BA6'}
          ref={task_4}
          y={-150}
          x={-1200}
        />
              <Circle          
          lineWidth={5}
          width={150}
          height={150}
          fill={'#177BA6'}
          ref={task_5}
          y={-150}
          x={-1200}
        />
        <Circle          
          lineWidth={5}
          width={200}
          height={200}
          stroke={'#2DAB2B'}
          ref={thread_1}
          y={100}
        />
        <Circle          
          lineWidth={5}
          width={200}
          height={200}
          stroke={'#2DAB2B'}
          ref={thread_2}
          x={-250}
          y={100}
        />
        <Circle          
          lineWidth={5}
          width={200}
          height={200}
          stroke={'#2DAB2B'}
          ref={thread_3}
          x={250}
          y={100}
        />
    </>
  );

  yield* task_1().position([-0, -150], 2)
  yield* task_1().position([-250, 100], 1)
  yield* thread_2().stroke('#BD2214', 0.1)

  yield* task_2().position([-0, -150], 2)
  yield* task_2().position([0, 100], 1)
  yield* thread_1().stroke('#BD2214', 0.1)

  yield* task_3().position([-0, -150], 2)
  yield* task_3().position([250, 100], 1)
  yield* thread_3().stroke('#BD2214', 0.1)

  yield* task_4().position([-0, -150], 2)
  yield* task_5().position([-250, -150], 2)

  yield* task_1().position([-250, +1500], 1)
  yield* thread_2().stroke('#2DAB2B', 0.1)

  yield task_4().position([-250, 100], 2)
  yield* task_5().position([-0, -150], 2)
  yield* thread_2().stroke('#BD2214', 0.1)

  yield* task_2().position([0, +1500], 1)
  yield* thread_1().stroke('#2DAB2B', 0.1)

  yield* task_5().position([-0, 100], 2)
  yield* thread_1().stroke('#BD2214', 0.1)

  yield task_3().position([250, +1500], 1)
  yield* waitFor(0.1)
  yield task_4().position([-250, +1500], 1)
  yield* waitFor(0.1)
  yield* task_5().position([0, +1500], 1)
  yield thread_3().stroke('#2DAB2B', 0.1)
  yield* waitFor(0.1)
  yield thread_2().stroke('#2DAB2B', 0.1)
  yield* waitFor(0.1)
  yield* thread_1().stroke('#2DAB2B', 0.1)

  yield* waitFor(5.0)
});