import {makeScene2D} from '@motion-canvas/2d';
import {all, waitFor, waitUntil} from '@motion-canvas/core/lib/flow';
import {Layout, Rect, Txt, Line} from '@motion-canvas/2d/lib/components';
import {createRef, makeRef, useScene} from '@motion-canvas/core/lib/utils';
import {map} from '@motion-canvas/core/lib/tweening';
import {createSignal} from '@motion-canvas/core/lib/signals';
import {Direction, Spacing, Vector2} from '@motion-canvas/core/lib/types';
import {slideTransition} from '@motion-canvas/core/lib/transitions';

export default makeScene2D(function* (view) {
  view.fill('#1B1D20'); // set the background of this scene
  
  const packaged_task = createRef<Txt>();
  const future = createRef<Txt>();
  const shared_ressource = createRef<Txt>();
  const thread = createRef<Txt>();
  const get_future = createRef<Txt>();
  const main_thread = createRef<Txt>();
  const line_Ref = createRef<Line>();

  const size = createSignal(500);
  const size2 = createSignal(500);

  view.add(
    <>
    <Txt
        ref={packaged_task}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={-500}
        y={-200}
      />
          <Txt
        ref={shared_ressource}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={0}
        y={50}
      />
        <Txt
        ref={get_future}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={-700}
        y={50}
      />
          <Txt
        ref={thread}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={400}
        y={-400}
      />
                <Txt
        ref={main_thread}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={-500}
        y={-400}
      />
      <Txt
        ref={future}
        fontSize={50}
        lineHeight={50}
        fontFamily={'JetBrains Mono'}
        fill={'#FCE0B0'}
        x={-500}
        y={300}
      />
      <Line          
          lineWidth={5}
          stroke={'#2DAB2B'}
          endArrow
          arrowSize={15}
          endOffset={size}
          ref={line_Ref}
          points={[[packaged_task().position.x() +50, packaged_task().position.y() + 50], [shared_ressource().position.x()-100, shared_ressource().position.y() - 50]]}
      />
      <Line          
          lineWidth={5}
          stroke={'#2DAB2B'}
          endArrow
          arrowSize={15}
          endOffset={size}
          points={[[future().position.x()+50, future().position.y() - 50], [shared_ressource().position.x()-100, shared_ressource().position.y() + 50]]}
      />
      <Line          
          lineWidth={5}
          stroke={'#177BA6'}
          endArrow
          arrowSize={15}
          endOffset={size2}
          points={[[packaged_task().position.x(), packaged_task().position.y() + 50], [future().position.x(), future().position.y() - 50]]}
      />
    </>
  );

  yield* main_thread().text('Main thread', 1);
  yield* waitFor(1.0)
  yield* packaged_task().text('std::packaged_task', 1);
  yield* waitFor(2.0)
  yield size2(500, 0).to(0, 2);
  yield get_future().text('GetFuture()', 1)
  yield* future().text('std::future', 1),

  yield* waitFor(2.0)
  yield size(500, 0).to(0, 2);
  yield* shared_ressource().text('Shared Ressource', 1);

  yield* waitFor(2.0)
  yield get_future().text('', 1)
  yield size2(0, 0).to(500, 1);

  yield* waitFor(2.0)
  yield* thread().text('std::thread', 1);

  yield* waitFor(1.0)
  yield packaged_task().position.x(400, 2)
  yield* line_Ref().points([[400, packaged_task().position.y() + 50], [shared_ressource().position.x() + 100, shared_ressource().position.y() - 50]], 2)
  yield* waitFor(5.0)
});