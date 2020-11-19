module Constants = {
  let triangles = 4;

  let triangle_strip = 5;

  let texture0 = 33984;

  let texture1 = 33985;

  let texture2 = 33986;

  let texture_2d = 3553;

  let blend = 3042;

  let texture_wrap_s = 10242;

  let texture_wrap_t = 10243;

  let clamp_to_edge = 33071;

  let src_alpha = 770;

  let one_minus_src_alpha = 771;

  let dst_alpha = 772;

  let depth_test = 2929;

  let cull_face = 2884;

  let rgb = 6407;

  let rgba = 6408;

  let triangle_fan = 6;

  let array_buffer = 34962;

  let element_array_buffer = 34963;

  let array_buffer_binding = 34964;

  let element_array_buffer_binding = 34965;

  let stream_draw = 35040;

  let static_draw = 35044;

  let dynamic_draw = 35048;

  let buffer_size = 34660;

  let buffer_usage = 34661;

  let float_ = 5126;

  let unsigned_int = 5125;

  let current_vertex_attrib = 34342;

  let fragment_shader = 35632;

  let vertex_shader = 35633;

  let max_vertex_attribs = 34921;

  let max_vertex_uniform_vectors = 36347;

  let max_varying_vectors = 36348;

  let max_combined_texture_image_units = 35661;

  let max_vertex_texture_image_units = 35660;

  let max_texture_image_units = 34930;

  let max_fragment_uniform_vectors = 36349;

  let shader_type = 35663;

  let delete_status = 35712;

  let link_status = 35714;

  let validate_status = 35715;

  let attached_shaders = 35717;

  let active_uniforms = 35718;

  let active_attributes = 35721;

  let shading_language_version = 35724;

  let current_program = 35725;

  let compile_status = 35713;

  let vendor = 7936;

  let renderer = 7937;

  let version = 7938;

  let float_vec2 = 35664;

  let float_vec3 = 35665;

  let float_vec4 = 35666;

  let int_vec2 = 35667;

  let int_vec3 = 35668;

  let int_vec4 = 35669;

  let bool_ = 35670;

  let bool_vec2 = 35671;

  let bool_vec3 = 35672;

  let bool_vec4 = 35673;

  let float_mat2 = 35674;

  let float_mat3 = 35675;

  let float_mat4 = 35676;

  let sampler_2d = 35678;

  let sampler_cube = 35680;

  let unpack_flip_y_webgl = 37440;

  let unpack_premultiply_alpha_webgl = 37441;

  let context_lost_webgl = 37442;

  let unpack_colorspace_conversion_webgl = 37443;

  let browser_default_webgl = 37444;

  let vertex_attrib_array_enabled = 34338;

  let vertex_attrib_array_size = 34339;

  let vertex_attrib_array_stride = 34340;

  let vertex_attrib_array_type = 34341;

  let vertex_attrib_array_normalized = 34922;

  let vertex_attrib_array_pointer = 34373;

  let vertex_attrib_array_buffer_binding = 34975;

  let depth_buffer_bit = 256;

  let stencil_buffer_bit = 1024;

  let color_buffer_bit = 16384;

  let unsigned_short = 5123;

  let unsigned_byte = 5121;

  let texture_mag_filter = 10240;

  let texture_min_filter = 10241;

  let nearest = 9728;

  let linear = 9729;

  let nearest_mipmap_nearest = 9984;

  let linear_mipmap_nearest = 9985;

  let nearest_mipmap_linear = 9986;

  let linear_mipmap_linear = 9987;

  let framebuffer = 36160;

  let color_attachment0 = 36064;
};

module Helpers = {
  type canvasT;
  [@bs.set] external setHiddenRAFID: ('a, int) => unit = "__hiddenrafid";
  [@bs.get] external getButton: 'eventT => int = "button";
  [@bs.get] external getClientX: 'eventT => int = "clientX";
  [@bs.get] external getClientY: 'eventT => int = "clientY";
  [@bs.get]
  external getChangedTouches: 'eventT => 'touchListT = "changedTouches";
  [@bs.val]
  external convertToArray: 'notarray => array('thing) =
    "Array.prototype.slice.call";
  [@bs.get] external getTouchIdentifier: 'touchT => int = "identifier";
  [@bs.send] external preventDefault: 'eventT => unit = "preventDefault";
  [@bs.get] external getWhich: 'eventT => int = "which";
  [@bs.send]
  external getBoundingClientRect: canvasT => 'leftAndTop =
    "getBoundingClientRect";
  [@bs.get] external getTop: 'a => int = "top";
  [@bs.get] external getLeft: 'a => int = "left";
  let getTouch0 = (e, canvas) => {
    let touches = convertToArray(getChangedTouches(e));
    switch (touches) {
    | [|t|] =>
      let rect = getBoundingClientRect(canvas);
      let x = getClientX(t) - getLeft(rect);
      let y = getClientY(t) - getTop(rect);
      Some((getTouchIdentifier(t), x, y));
    | _ => None
    };
  };
  [@bs.get] external getCanvasWidth: canvasT => int = "width";
  [@bs.get] external getCanvasHeight: canvasT => int = "height";
  [@bs.set] external setWidth: (canvasT, int) => unit = "width";
  [@bs.set] external setHeight: (canvasT, int) => unit = "height";
  [@bs.val]
  external createElement: string => canvasT = "document.createElement";
  let createCanvas = () => createElement("canvas");
  [@bs.val] external addToBody: canvasT => unit = "document.body.appendChild";
  [@bs.send]
  external getContext: (canvasT, string, 'options) => 'context = "getContext";
  type styleT;
  [@bs.get] external getStyle: canvasT => styleT = "style";
  [@bs.set] external setWidthStyle: (styleT, string) => unit = "width";
  [@bs.set] external setHeightStyle: (styleT, string) => unit = "height";
  [@bs.set]
  external setBackgroundColor: (styleT, string) => unit = "backgroundColor";
  type httpRequestT;
  [@bs.new]
  external makeXMLHttpRequest: unit => httpRequestT = "XMLHttpRequest";
  [@bs.send]
  external openFile:
    (httpRequestT, ~kind: string, ~filename: string, ~whatIsThis: bool) => unit =
    "open";
  [@bs.set]
  external onreadystatechange: (httpRequestT, unit => unit) => unit =
    "onreadystatechange";
  [@bs.set]
  external setResponseType: (httpRequestT, string) => unit = "responseType";
  [@bs.get] external getReadyState: httpRequestT => int = "readyState";
  [@bs.get] external getStatus: httpRequestT => int = "status";
  [@bs.get] external getResponseText: httpRequestT => string = "responseText";
  type arrayBufferT;
  type soundT;
  type audioContextT;
  type audioLocT;
  type audioGainT;
  let makeAudioContext: unit => audioContextT = [%bs.raw
    {| function(_) { return new (window.AudioContext || window.webkitAudioContext)(); } |}
  ];
  [@bs.get] external getResponse: httpRequestT => arrayBufferT = "response";
  [@bs.send]
  external decodeAudioData:
    (audioContextT, arrayBufferT, soundT => unit) => unit =
    "decodeAudioData";
  [@bs.send]
  external createBufferSource: audioContextT => audioLocT =
    "createBufferSource";
  [@bs.send] external createGain: audioContextT => audioLocT = "createGain";
  [@bs.get] external getGain: 'a => audioGainT = "gain";
  [@bs.set] external setGainValue: (audioGainT, float) => unit = "value";
  [@bs.set]
  external setAudioSourceBuffer: (audioLocT, soundT) => unit = "buffer";
  [@bs.get]
  external getAudioContextDestination: audioContextT => audioLocT =
    "destination";
  [@bs.send]
  external audioSourceConnect: (audioLocT, audioLocT) => unit = "connect";
  [@bs.send] external audioSourceStart: (audioLocT, float) => unit = "start";
  [@bs.set] external setAudioSourceLoop: (audioLocT, bool) => unit = "loop";
  [@bs.send]
  external sendRequest: (httpRequestT, Js.null('a)) => unit = "send";
};
module Document = {
  type t;
  type element;
  type window;
  let window: window = [%bs.raw "window"];

  let document: t = [%bs.raw "document"];

  [@bs.val]
  external getElementById: string => Js.nullable(element) =
    "document.getElementById";

  [@bs.send] external getContext: (element, string) => 'context = "getContext";

  [@bs.get] external getWidth: element => int = "width";

  [@bs.get] external getHeight: element => int = "height";

  [@bs.val]
  external requestAnimationFrame: (unit => unit) => int =
    "window.requestAnimationFrame";

  [@bs.val]
  external cancelAnimationFrame: int => unit = "window.cancelAnimationFrame";

  [@bs.val] external now: unit => float = "Date.now";

  [@bs.send]
  external addEventListener: ('window, string, 'eventT => unit) => unit =
    "addEventListener";

  [@bs.val] external devicePixelRatio: float = "window.devicePixelRatio";

  [@bs.set] external setTitle: (t, string) => unit = "title";
};

module Events = {
  type buttonStateT =
    | LeftButton
    | MiddleButton
    | RightButton;

  type stateT =
    | MouseDown
    | MouseUp;

  type keycodeT =
    | Backspace
    | Delete
    | Tab
    | Enter
    | Escape
    | Space
    | Quote
    | Comma
    | Minus
    | Period
    | Slash
    | Num_0
    | Num_1
    | Num_2
    | Num_3
    | Num_4
    | Num_5
    | Num_6
    | Num_7
    | Num_8
    | Num_9
    | Semicolon
    | Equals
    | OpenBracket
    | Backslash
    | CloseBracket
    | A
    | B
    | C
    | D
    | E
    | F
    | G
    | H
    | I
    | J
    | K
    | L
    | M
    | N
    | O
    | P
    | Q
    | R
    | S
    | T
    | U
    | V
    | W
    | X
    | Y
    | Z
    | Right
    | Left
    | Down
    | Up
    | LeftCtrl
    | LeftShift
    | LeftAlt
    | LeftOsKey
    | RightCtrl
    | RightShift
    | RightAlt
    | RightOsKey
    | CapsLock
    | Backtick
    | Nothing;

  let keycodeMap: Int32.t => keycodeT =
    i32 =>
      switch (Int32.to_int(i32)) {
      | 8 => Backspace
      | 9 => Tab
      | 13 => Enter
      | 16 => LeftShift
      | 17 => LeftCtrl
      | 18 => LeftAlt
      | 20 => CapsLock
      | 27 => Escape
      | 32 => Space
      | 37 => Left
      | 38 => Up
      | 39 => Right
      | 40 => Down
      | 46 => Delete
      | 48 => Num_0
      | 49 => Num_1
      | 50 => Num_2
      | 51 => Num_3
      | 52 => Num_4
      | 53 => Num_5
      | 54 => Num_6
      | 55 => Num_7
      | 56 => Num_8
      | 57 => Num_9
      | 65 => A
      | 66 => B
      | 67 => C
      | 68 => D
      | 69 => E
      | 70 => F
      | 71 => G
      | 72 => H
      | 73 => I
      | 74 => J
      | 75 => K
      | 76 => L
      | 77 => M
      | 78 => N
      | 79 => O
      | 80 => P
      | 81 => Q
      | 82 => R
      | 83 => S
      | 84 => T
      | 85 => U
      | 86 => V
      | 87 => W
      | 88 => X
      | 89 => Y
      | 90 => Z
      | 91 => LeftOsKey
      | 93 => RightOsKey
      | 186 => Semicolon
      | 187 => Equals
      | 188 => Comma
      | 189 => Minus
      | 190 => Period
      | 191 => Slash
      | 192 => Backtick
      | 219 => OpenBracket
      | 220 => Backslash
      | 221 => CloseBracket
      | 222 => Quote
      | _ => Nothing
      };
};

module Gl = {
  open Helpers;

  let target = "web";
  type contextT;
  module type FileT = {
    type t;
    let readFile: (~filename: string, ~cb: string => unit) => unit;
  };
  module File = {
    type t;
    let readFile = (~filename, ~cb) => {
      let rawFile = makeXMLHttpRequest();
      openFile(rawFile, ~kind="GET", ~filename, ~whatIsThis=false);
      onreadystatechange(rawFile, () =>
        if (getReadyState(rawFile) === 4
            && (getStatus(rawFile) === 200 || getStatus(rawFile) === 0)) {
          cb(getResponseText(rawFile));
        }
      );
      sendRequest(rawFile, Js.null);
    };
  };
  module type WindowT = {
    type t;
    let getWidth: t => int;
    let getHeight: t => int;
    let getPixelWidth: t => int;
    let getPixelHeight: t => int;
    let getPixelScale: t => float;
    let init: (~screen: string=?, ~argv: array(string)) => t;
    let setWindowSize: (~window: t, ~width: int, ~height: int) => unit;
    let setWindowTitle: (~window: t, ~title: string) => unit;
    let getContext: t => contextT;
  };
  module Window = {
    type t = (canvasT, audioContextT);
    let getWidth = ((window, _ac)) =>
      int_of_float @@
      float_of_int(getCanvasWidth(window))
      /. Document.devicePixelRatio;
    let getHeight = ((window, _ac)) =>
      int_of_float @@
      float_of_int(getCanvasHeight(window))
      /. Document.devicePixelRatio;
    let getPixelWidth = ((window, _ac)) =>
      int_of_float @@ float_of_int @@ getCanvasWidth(window);
    let getPixelHeight = ((window, _ac)) =>
      int_of_float @@ float_of_int @@ getCanvasHeight(window);
    let getPixelScale = (_: t) => Document.devicePixelRatio;
    let init = (~screen=?, ~argv as _) => {
      let node =
        switch (screen) {
        | None => None
        | Some(id) => Js.Nullable.toOption(Document.getElementById(id))
        };
      let canvas =
        switch (node) {
        | Some(node) => Obj.magic(node)
        | None =>
          let canvas = createCanvas();
          addToBody(canvas);
          canvas;
        };
      setBackgroundColor(getStyle(canvas), "black");
      (canvas, makeAudioContext());
    };
    let setWindowSize = (~window as (w, _), ~width, ~height) => {
      setWidth(
        w,
        int_of_float @@ float_of_int(width) *. Document.devicePixelRatio,
      );
      setHeight(
        w,
        int_of_float @@ float_of_int(height) *. Document.devicePixelRatio,
      );
      setWidthStyle(getStyle(w), string_of_int(width) ++ "px");
      setHeightStyle(getStyle(w), string_of_int(height) ++ "px");
    };
    let setWindowTitle = (~window as _, ~title) =>
      Document.setTitle(Document.document, title);
    let getContext = ((window, _ac)): contextT =>
      getContext(
        window,
        "webgl",
        {"preserveDrawingBuffer": true, "antialias": true},
      );
  };
  module type AudioT = {
    type t;
    let loadSound: (Window.t, string, t => unit) => unit;
    let playSound: (Window.t, t, ~volume: float, ~loop: bool) => unit;
  };
  module Audio = {
    type t = soundT;
    let loadSound = ((_window, audioctx), path, cb) => {
      let rawFile = makeXMLHttpRequest();
      setResponseType(rawFile, "arraybuffer");
      openFile(rawFile, ~kind="GET", ~filename=path, ~whatIsThis=true);
      onreadystatechange(rawFile, () =>
        if (getReadyState(rawFile) === 4
            && (getStatus(rawFile) === 200 || getStatus(rawFile) === 0)) {
          decodeAudioData(audioctx, getResponse(rawFile), cb);
        }
      );
      sendRequest(rawFile, Js.null);
    };
    let playSound = ((_window, audioctx), sound, ~volume, ~loop) => {
      let src = createBufferSource(audioctx);
      let gain = createGain(audioctx);
      setGainValue(getGain(gain), volume);
      setAudioSourceBuffer(src, sound);
      audioSourceConnect(src, gain);
      audioSourceConnect(gain, getAudioContextDestination(audioctx));
      audioSourceStart(src, 0.0);
      setAudioSourceLoop(src, loop);
    };
  };
  module Events = Events;
  type mouseButtonEventT =
    (~button: Events.buttonStateT, ~state: Events.stateT, ~x: int, ~y: int) =>
    unit;
  let render =
      (
        ~window as (canvas, _ac): Window.t,
        ~mouseDown: option(mouseButtonEventT)=?,
        ~mouseUp: option(mouseButtonEventT)=?,
        ~mouseMove: option((~x: int, ~y: int) => unit)=?,
        ~keyDown: option((~keycode: Events.keycodeT, ~repeat: bool) => unit)=?,
        ~keyUp: option((~keycode: Events.keycodeT) => unit)=?,
        ~windowResize: option(unit => unit)=?,
        ~displayFunc: float => unit,
        (),
      ) => {
    let singleTouchId = ref(None);
    switch (mouseDown) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(canvas, "touchstart", e =>
        switch (Helpers.getTouch0(e, canvas)) {
        | Some((touchId, x, y)) =>
          switch (singleTouchId^) {
          | None =>
            singleTouchId := Some(touchId);
            Helpers.preventDefault(e);
            cb(~button=Events.LeftButton, ~state=Events.MouseDown, ~x, ~y);
          | _ => singleTouchId := None
          }
        | None => ()
        }
      );
      Document.addEventListener(
        canvas,
        "mousedown",
        e => {
          let button =
            switch (getButton(e)) {
            | 0 => Events.LeftButton
            | 1 => Events.MiddleButton
            | 2 => Events.RightButton
            | _ => assert(false)
            };
          let state = Events.MouseDown;
          let rect = getBoundingClientRect(canvas);
          let x = getClientX(e) - getLeft(rect);
          let y = getClientY(e) - getTop(rect);
          cb(~button, ~state, ~x, ~y);
        },
      );
    };
    switch (mouseUp) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(canvas, "touchend", e =>
        switch (getTouch0(e, canvas)) {
        | Some((touchId, x, y)) =>
          switch (singleTouchId^) {
          | Some(id) when id == touchId =>
            singleTouchId := None;
            preventDefault(e);
            cb(~button=Events.LeftButton, ~state=Events.MouseUp, ~x, ~y);
          | _ => ()
          }
        | None => ()
        }
      );
      Document.addEventListener(canvas, "touchcancel", e =>
        switch (getTouch0(e, canvas)) {
        | Some((touchId, x, y)) =>
          switch (singleTouchId^) {
          | Some(id) when id == touchId =>
            singleTouchId := None;
            preventDefault(e);
            cb(~button=Events.LeftButton, ~state=Events.MouseUp, ~x, ~y);
          | _ => ()
          }
        | None => ()
        }
      );
      Document.addEventListener(
        canvas,
        "mouseup",
        e => {
          let button =
            switch (getButton(e)) {
            | 0 => Events.LeftButton
            | 1 => Events.MiddleButton
            | 2 => Events.RightButton
            | _ => assert(false)
            };
          let state = Events.MouseUp;
          let rect = getBoundingClientRect(canvas);
          let x = getClientX(e) - getLeft(rect);
          let y = getClientY(e) - getTop(rect);
          cb(~button, ~state, ~x, ~y);
        },
      );
    };
    switch (mouseMove) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(canvas, "touchmove", e =>
        switch (getTouch0(e, canvas)) {
        | Some((touchId, x, y)) =>
          switch (singleTouchId^) {
          | Some(id) when id == touchId =>
            preventDefault(e);
            cb(~x, ~y);
          | _ => ()
          }
        | None => ()
        }
      );
      Document.addEventListener(
        canvas,
        "mousemove",
        e => {
          let rect = getBoundingClientRect(canvas);
          let x = getClientX(e) - getLeft(rect);
          let y = getClientY(e) - getTop(rect);
          cb(~x, ~y);
        },
      );
    };
    let keyLastPressed = ref([]);
    switch (keyDown) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(
        Document.window,
        "keydown",
        e => {
          let keycode = Int32.of_int(getWhich(e));
          let repeat =
            List.fold_left(
              (acc, k) => acc || k === keycode,
              false,
              keyLastPressed^,
            );
          if (!repeat) {
            keyLastPressed := [keycode, ...keyLastPressed^];
          };
          cb(~keycode=Events.keycodeMap(keycode), ~repeat);
        },
      )
    };
    switch (keyUp) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(
        Document.window,
        "keyup",
        e => {
          let keycode = Int32.of_int(getWhich(e));
          keyLastPressed := List.filter(k => k !== keycode, keyLastPressed^);
          cb(~keycode=Events.keycodeMap(keycode));
        },
      )
    };
    switch (windowResize) {
    | None => ()
    | Some(cb) =>
      Document.addEventListener(Document.window, "resize", _ => cb())
    };
    let frame = ref(None);
    let rec tick = (prev, ()) => {
      let now = Document.now();
      displayFunc(now -. prev);
      let id = Document.requestAnimationFrame(tick(now));
      frame := Some(id);
      setHiddenRAFID(canvas, id);
    };
    let id = Document.requestAnimationFrame(tick(Document.now()));
    frame := Some(id);
    setHiddenRAFID(canvas, id);
    play =>
      switch (frame^) {
      | None =>
        if (play) {
          let id = Document.requestAnimationFrame(tick(Document.now()));
          frame := Some(id);
          setHiddenRAFID(canvas, id);
          true;
        } else {
          false;
        }
      | Some(id) =>
        if (!play) {
          Document.cancelAnimationFrame(id);
          frame := None;
          false;
        } else {
          true;
        }
      };
  };
  type programT;
  type shaderT;
  [@bs.send]
  external clearColor:
    (~context: contextT, ~r: float, ~g: float, ~b: float, ~a: float) => unit =
    "clearColor";
  [@bs.send]
  external createProgram: (~context: contextT) => programT = "createProgram";
  [@bs.send]
  external createShader: (~context: contextT, int) => shaderT = "createShader";
  [@bs.send]
  external _shaderSource:
    (~context: contextT, ~shader: shaderT, ~source: string) => unit =
    "shaderSource";
  let shaderSource = (~context, ~shader, ~source) =>
    _shaderSource(
      ~context,
      ~shader,
      ~source="#version 100 \n precision highp float; \n" ++ source,
    );
  [@bs.send]
  external compileShader: (~context: contextT, shaderT) => unit =
    "compileShader";
  [@bs.send]
  external attachShader:
    (~context: contextT, ~program: programT, ~shader: shaderT) => unit =
    "attachShader";
  [@bs.send]
  external deleteShader: (~context: contextT, shaderT) => unit =
    "deleteShader";
  [@bs.send]
  external linkProgram: (~context: contextT, programT) => unit = "linkProgram";
  [@bs.send]
  external useProgram: (~context: contextT, programT) => unit = "useProgram";
  type bufferT;
  type attributeT;
  type uniformT;
  [@bs.send]
  external createBuffer: (~context: contextT) => bufferT = "createBuffer";
  [@bs.send]
  external bindBuffer:
    (~context: contextT, ~target: int, ~buffer: bufferT) => unit =
    "bindBuffer";
  type textureT;
  [@bs.send]
  external createTexture: (~context: contextT) => textureT = "createTexture";
  [@bs.send]
  external activeTexture: (~context: contextT, int) => unit = "activeTexture";
  [@bs.send]
  external bindTexture:
    (~context: contextT, ~target: int, ~texture: textureT) => unit =
    "bindTexture";
  [@bs.send]
  external texParameteri:
    (~context: contextT, ~target: int, ~pname: int, ~param: int) => unit =
    "texParameteri";
  type framebufferT;
  [@bs.send]
  external createFramebuffer: (~context: contextT) => framebufferT =
    "createFramebuffer";
  [@bs.send]
  external bindFramebuffer:
    (~context: contextT, ~target: int, ~framebuffer: framebufferT) => unit =
    "bindFramebuffer";
  [@bs.send]
  external bindDefaultFramebuffer:
    (~context: contextT, ~target: int, [@bs.as {json|null|json}] _) => unit =
    "bindFramebuffer";
  [@bs.send]
  external framebufferTexture2D:
    (
      ~context: contextT,
      ~target: int,
      ~attachment: int,
      ~texTarget: int,
      ~texture: textureT,
      [@bs.as {json|0|json}] _
    ) =>
    unit =
    "framebufferTexture2D";
  [@bs.send] external enable: (~context: contextT, int) => unit = "enable";
  [@bs.send] external disable: (~context: contextT, int) => unit = "disable";
  [@bs.send]
  external blendFunc: (~context: contextT, int, int) => unit = "blendFunc";
  [@bs.new]
  external createFloat32ArrayOfArray: array(float) => 'flot32array =
    "Float32Array";
  [@bs.new] external createFloat32Array: int => 'float32array = "Float32Array";
  [@bs.new]
  external createFloat64ArrayOfArray: array(float) => 'flot64array =
    "Float64Array";
  [@bs.new] external createFloat64Array: int => 'float64array = "Float64Array";
  [@bs.new]
  external createIntArrayOfArray: array(int) => 'int32array = "Int32Array";
  [@bs.new]
  external createInt32ArrayOfArray: array(int32) => 'int32array =
    "Int32Array";
  [@bs.new] external createIntArray: int => 'int32array = "Int32Array";
  [@bs.new] external createInt32Array: int => 'int32array = "Int32Array";
  [@bs.new]
  external createUint16ArrayOfArray: array(int) => 'uint16array =
    "Uint16Array";
  [@bs.new] external createUint16Array: int => 'uint16array = "Uint16Array";
  [@bs.new]
  external createInt16ArrayOfArray: array(int) => 'int16array = "Int16Array";
  [@bs.new] external createInt16Array: int => 'int16array = "Int16Array";
  [@bs.new]
  external createUint8ArrayOfArray: array(int) => 'uint8array = "Uint8Array";
  [@bs.new] external createUint8Array: int => 'uint8array = "Uint8Array";
  [@bs.new]
  external createInt8ArrayOfArray: array(int) => 'int8array = "Int8Array";
  [@bs.new] external createInt8Array: int => 'int8array = "Int8Array";
  [@bs.new]
  external createCharArrayOfArray: array(char) => 'uint8array = "Uint8Array";
  [@bs.send] external sub: ('a, int, int) => 'a = "subarray";
  module type Bigarray = {
    type t('a, 'b);
    type float64_elt;
    type float32_elt;
    type int16_unsigned_elt;
    type int16_signed_elt;
    type int8_unsigned_elt;
    type int8_signed_elt;
    type int_elt;
    type int32_elt;
    type int64_elt;
    type kind('a, 'b) =
      | Float64: kind(float, float64_elt)
      | Float32: kind(float, float32_elt)
      | Int16: kind(int, int16_signed_elt)
      | Uint16: kind(int, int16_unsigned_elt)
      | Int8: kind(int, int8_signed_elt)
      | Uint8: kind(int, int8_unsigned_elt)
      | Char: kind(char, int8_unsigned_elt)
      | Int: kind(int, int_elt)
      | Int64: kind(int64, int64_elt)
      | Int32: kind(int32, int32_elt);
    let create: (kind('a, 'b), int) => t('a, 'b);
    let of_array: (kind('a, 'b), array('a)) => t('a, 'b);
    let dim: t('a, 'b) => int;
    let blit: (t('a, 'b), t('a, 'b)) => unit;
    let unsafe_blit:
      (t('a, 'b), t('a, 'b), ~offset: int, ~numOfBytes: int) => unit;
    let get: (t('a, 'b), int) => 'a;
    let unsafe_get: (t('a, 'b), int) => 'a;
    let set: (t('a, 'b), int, 'a) => unit;
    let unsafe_set: (t('a, 'b), int, 'a) => unit;
    let sub: (t('a, 'b), ~offset: int, ~len: int) => t('a, 'b);
  };
  module Bigarray = {
    type t('a, 'b);
    type float64_elt;
    type float32_elt;
    type int16_unsigned_elt;
    type int16_signed_elt;
    type int8_unsigned_elt;
    type int8_signed_elt;
    type int_elt;
    type int32_elt;
    type int64_elt;
    type kind('a, 'b) =
      | Float64: kind(float, float64_elt)
      | Float32: kind(float, float32_elt)
      | Int16: kind(int, int16_signed_elt)
      | Uint16: kind(int, int16_unsigned_elt)
      | Int8: kind(int, int8_signed_elt)
      | Uint8: kind(int, int8_unsigned_elt)
      | Char: kind(char, int8_unsigned_elt)
      | Int: kind(int, int_elt)
      | Int64: kind(int64, int64_elt)
      | Int32: kind(int32, int32_elt);
    let create = (type a, type b, kind: kind(a, b), size): t(a, b) =>
      switch (kind) {
      | Float64 => createFloat64Array(size)
      | Float32 => createFloat32Array(size)
      | Int16 => createInt16Array(size)
      | Uint16 => createUint16Array(size)
      | Int8 => createInt8Array(size)
      | Uint8 => createUint8Array(size)
      | Char => createUint8Array(size)
      | Int => createIntArray(size)
      | Int32 => createInt32Array(size)
      | Int64 => assert(false)
      };
    let of_array =
        (type a, type b, kind: kind(a, b), arr: array(a)): t(a, b) =>
      switch (kind) {
      | Float64 => createFloat64ArrayOfArray(arr)
      | Float32 => createFloat32ArrayOfArray(arr)
      | Int16 => createInt16ArrayOfArray(arr)
      | Uint16 => createUint16ArrayOfArray(arr)
      | Int8 => createInt8ArrayOfArray(arr)
      | Uint8 => createUint8ArrayOfArray(arr)
      | Char => createCharArrayOfArray(arr)
      | Int => createIntArrayOfArray(arr)
      | Int32 => createInt32ArrayOfArray(arr)
      | Int64 => assert(false)
      };
    [@bs.get] external dim: 'a => int = "length";
    [@bs.send] external blit: (t('a, 'b), t('a, 'b)) => unit = "set";
    [@bs.send]
    external unsafe_blit: (t('a, 'b), t('a, 'b), ~offset: int) => unit =
      "set";
    let unsafe_blit:
      (t('a, 'b), t('a, 'b), ~offset: int, ~numOfBytes: int) => unit =
      (arr, arr2, ~offset, ~numOfBytes as _) =>
        unsafe_blit(arr2, arr, ~offset);
    [@bs.get_index] external get: (t('a, 'b), int) => 'a = "";
    [@bs.get_index] external unsafe_get: (t('a, 'b), int) => 'a = "";
    [@bs.set_index] external set: (t('a, 'b), int, 'a) => unit = "";
    [@bs.set_index] external unsafe_set: (t('a, 'b), int, 'a) => unit = "";
    let sub = (arr, ~offset, ~len) => sub(arr, offset, offset + len);
  };
  [@bs.send]
  external texSubImage2D:
    (
      ~context: contextT,
      ~target: int,
      ~level: int,
      ~xoffset: int,
      ~yoffset: int,
      ~width: int,
      ~height: int,
      ~format: int,
      ~type_: int,
      ~pixels: Bigarray.t('a, 'b)
    ) =>
    unit =
    "texSubImage2D";
  [@bs.send]
  external readPixels:
    (
      ~context: contextT,
      ~x: int,
      ~y: int,
      ~width: int,
      ~height: int,
      ~format: int,
      ~type_: int,
      ~pixels: Bigarray.t(int, Bigarray.int8_unsigned_elt)
    ) =>
    unit =
    "readPixels";
  let readPixels_RGBA = (~context, ~x, ~y, ~width, ~height) => {
    let data = createUint8Array(width * height * 4);
    readPixels(
      ~context,
      ~x,
      ~y,
      ~width,
      ~height,
      ~format=Constants.rgba,
      ~type_=Constants.unsigned_byte,
      ~pixels=data,
    );
    data;
  };
  type imageT;
  [@bs.get] external getImageWidth: imageT => int = "width";
  [@bs.get] external getImageHeight: imageT => int = "height";
  type loadOptionT =
    | LoadAuto
    | LoadL
    | LoadLA
    | LoadRGB
    | LoadRGBA;
  [@bs.new] external makeImage: unit => imageT = "Image";
  [@bs.set] external setSrc: (imageT, string) => unit = "src";
  [@bs.send]
  external addEventListener: (imageT, string, unit => unit) => unit =
    "addEventListener";
  [@bs.val] external btoa: string => string = "btoa";
  let loadImage = (~filename, ~loadOption=?, ~callback, ()) =>
    switch (loadOption) {
    | _ =>
      let image = makeImage();
      setSrc(image, filename);
      addEventListener(image, "load", () => callback(Some(image)));
    };
  let loadImageFromMemory = (~data, ~loadOption as _=?, ~callback, ()) => {
    let image = makeImage();
    setSrc(image, "data:image/png;base64," ++ btoa(data));
    addEventListener(image, "load", () => callback(Some(image)));
  };
  [@bs.send]
  external _texImage2DWithImage:
    (
      ~context: contextT,
      ~target: int,
      ~level: int,
      ~internalFormat: int,
      ~format: int,
      ~type_: int,
      ~image: imageT
    ) =>
    unit =
    "texImage2D";
  let texImage2DWithImage = (~context, ~target, ~level, ~image) =>
    _texImage2DWithImage(
      ~context,
      ~target,
      ~level,
      ~internalFormat=Constants.rgba,
      ~format=Constants.rgba,
      ~type_=Constants.unsigned_byte,
      ~image,
    );
  [@bs.send]
  external _texImage2D:
    (
      ~context: contextT,
      ~target: int,
      ~level: int,
      ~internalFormat: int,
      ~width: int,
      ~height: int,
      ~border: int,
      ~format: int,
      ~type_: int,
      ~data: Bigarray.t('a, 'b)
    ) =>
    unit =
    "texImage2D";
  let texImage2D_RGBA =
      (~context, ~target, ~level, ~width, ~height, ~border, ~data) =>
    _texImage2D(
      ~context,
      ~target,
      ~level,
      ~internalFormat=Constants.rgba,
      ~width,
      ~height,
      ~border,
      ~format=Constants.rgba,
      ~type_=Constants.unsigned_byte,
      ~data,
    );
  let texImage2D_null:
    (
      ~context: contextT,
      ~target: int,
      ~level: int,
      ~width: int,
      ~height: int
    ) =>
    unit = [%bs.raw
    {| function(gl, target, level, width, height) {
  gl.texImage2D(target, level, gl.RGBA, width, height, 0, gl.RGBA, gl.UNSIGNED_BYTE, null)
} |}
  ];
  [@bs.send]
  external vertexAttribDivisor:
    (~context: contextT, ~attribute: attributeT, ~divisor: int) => unit =
    "vertexAttribDivisor";
  [@bs.send]
  external bufferData:
    (
      ~context: contextT,
      ~target: int,
      ~data: Bigarray.t('a, 'b),
      ~usage: int
    ) =>
    unit =
    "bufferData";
  [@bs.send]
  external viewport:
    (~context: contextT, ~x: int, ~y: int, ~width: int, ~height: int) => unit =
    "viewport";
  [@bs.send]
  external clear: (~context: contextT, ~mask: int) => unit = "clear";
  [@bs.send]
  external getUniformLocation:
    (~context: contextT, ~program: programT, ~name: string) => uniformT =
    "getUniformLocation";
  [@bs.send]
  external getAttribLocation:
    (~context: contextT, ~program: programT, ~name: string) => attributeT =
    "getAttribLocation";
  [@bs.send]
  external enableVertexAttribArray:
    (~context: contextT, ~attribute: attributeT) => unit =
    "enableVertexAttribArray";
  [@bs.send]
  external _vertexAttribPointer:
    (
      ~context: contextT,
      ~attribute: attributeT,
      ~size: int,
      ~type_: int,
      ~normalize: bool,
      ~stride: int,
      ~offset: int
    ) =>
    unit =
    "vertexAttribPointer";
  let vertexAttribPointer =
      (~context, ~attribute, ~size, ~type_, ~normalize, ~stride, ~offset) => {
    let normalize = if (normalize) {true} else {false};
    _vertexAttribPointer(
      ~context,
      ~attribute,
      ~size,
      ~type_,
      ~normalize,
      ~stride,
      ~offset,
    );
  };
  module type Mat4T = {
    type t;
    let to_array: t => array(float);
    let create: unit => t;
    let identity: (~out: t) => unit;
    let translate: (~out: t, ~matrix: t, ~vec: array(float)) => unit;
    let scale: (~out: t, ~matrix: t, ~vec: array(float)) => unit;
    let rotate:
      (~out: t, ~matrix: t, ~rad: float, ~vec: array(float)) => unit;
    let ortho:
      (
        ~out: t,
        ~left: float,
        ~right: float,
        ~bottom: float,
        ~top: float,
        ~near: float,
        ~far: float
      ) =>
      unit;
    let perspective:
      (~out: t, ~fovy: float, ~aspect: float, ~near: float, ~far: float) =>
      unit;
    let lookAt:
      (
        ~out: t,
        ~eye: array(float),
        ~center: array(float),
        ~up: array(float)
      ) =>
      unit;
  };
  module Mat4: Mat4T = {
    type t = array(float);
    let to_array = a => a;
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external create: unit => t = "create";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external identity: (~out: t) => unit = "identity";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external translate: (~out: t, ~matrix: t, ~vec: array(float)) => unit =
      "translate";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external scale: (~out: t, ~matrix: t, ~vec: array(float)) => unit =
      "scale";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external rotate:
      (~out: t, ~matrix: t, ~rad: float, ~vec: array(float)) => unit =
      "rotate";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external ortho:
      (
        ~out: t,
        ~left: float,
        ~right: float,
        ~bottom: float,
        ~top: float,
        ~near: float,
        ~far: float
      ) =>
      unit =
      "ortho";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external perspective:
      (~out: t, ~fovy: float, ~aspect: float, ~near: float, ~far: float) =>
      unit =
      "perspective";
    [@bs.scope "mat4"] [@bs.module "gl-matrix"]
    external lookAt:
      (
        ~out: t,
        ~eye: array(float),
        ~center: array(float),
        ~up: array(float)
      ) =>
      unit =
      "lookAt";
  };
  [@bs.send]
  external uniform1i:
    (~context: contextT, ~location: uniformT, ~value: int) => unit =
    "uniform1i";
  [@bs.send]
  external uniform1f:
    (~context: contextT, ~location: uniformT, ~value: float) => unit =
    "uniform1f";
  [@bs.send]
  external uniform2f:
    (~context: contextT, ~location: uniformT, ~v1: float, ~v2: float) => unit =
    "uniform2f";
  [@bs.send]
  external uniform3f:
    (
      ~context: contextT,
      ~location: uniformT,
      ~v1: float,
      ~v2: float,
      ~v3: float
    ) =>
    unit =
    "uniform3f";
  [@bs.send]
  external uniform4f:
    (
      ~context: contextT,
      ~location: uniformT,
      ~v1: float,
      ~v2: float,
      ~v3: float,
      ~v4: float
    ) =>
    unit =
    "uniform4f";
  [@bs.send]
  external _uniformMatrix4fv:
    (
      ~context: contextT,
      ~location: uniformT,
      ~transpose: bool,
      ~value: Mat4.t
    ) =>
    unit =
    "uniformMatrix4fv";
  let uniformMatrix4fv = (~context, ~location, ~value) =>
    _uniformMatrix4fv(~context, ~location, ~transpose=false, ~value);
  type shaderParamsInternalT('a) =
    | Shader_delete_status_internal: shaderParamsInternalT(bool)
    | Compile_status_internal: shaderParamsInternalT(bool)
    | Shader_type_internal: shaderParamsInternalT(int);
  type programParamsInternalT('a) =
    | Program_delete_status_internal: programParamsInternalT(bool)
    | Link_status_internal: programParamsInternalT(bool)
    | Validate_status_internal: programParamsInternalT(bool);
  type shaderParamsT =
    | Shader_delete_status
    | Compile_status
    | Shader_type;
  type programParamsT =
    | Program_delete_status
    | Link_status
    | Validate_status;
  [@bs.get]
  external deleteStatus: (~context: contextT) => int = "DELETE_STATUS";
  [@bs.get]
  external compileStatus: (~context: contextT) => int = "COMPILE_STATUS";
  [@bs.get] external linkStatus: (~context: contextT) => int = "LINK_STATUS";
  [@bs.get]
  external validateStatus: (~context: contextT) => int = "VALIDATE_STATUS";
  [@bs.get] external shaderType: (~context: contextT) => int = "SHADER_TYPE";
  [@bs.send]
  external _getProgramParameter:
    (
      ~context: contextT,
      ~program: programT,
      ~paramName: int,
      [@bs.ignore] programParamsInternalT('a)
    ) =>
    'a =
    "getProgramParameter";
  let getProgramParameter = (~context, ~program, ~paramName) =>
    switch (paramName) {
    | Program_delete_status =>
      if (_getProgramParameter(
            ~context,
            ~program,
            ~paramName=deleteStatus(~context),
            Program_delete_status_internal,
          )) {
        1;
      } else {
        0;
      }
    | Link_status =>
      if (_getProgramParameter(
            ~context,
            ~program,
            ~paramName=linkStatus(~context),
            Link_status_internal,
          )) {
        1;
      } else {
        0;
      }
    | Validate_status =>
      if (_getProgramParameter(
            ~context,
            ~program,
            ~paramName=validateStatus(~context),
            Validate_status_internal,
          )) {
        1;
      } else {
        0;
      }
    };
  [@bs.send]
  external _getShaderParameter:
    (
      ~context: contextT,
      ~shader: shaderT,
      ~paramName: int,
      [@bs.ignore] shaderParamsInternalT('a)
    ) =>
    'a =
    "getShaderParameter";
  let getShaderParameter = (~context, ~shader, ~paramName) =>
    switch (paramName) {
    | Shader_delete_status =>
      if (_getShaderParameter(
            ~context,
            ~shader,
            ~paramName=deleteStatus(~context),
            Shader_delete_status_internal,
          )) {
        1;
      } else {
        0;
      }
    | Compile_status =>
      if (_getShaderParameter(
            ~context,
            ~shader,
            ~paramName=compileStatus(~context),
            Compile_status_internal,
          )) {
        1;
      } else {
        0;
      }
    | Shader_type =>
      _getShaderParameter(
        ~context,
        ~shader,
        ~paramName=shaderType(~context),
        Shader_type_internal,
      )
    };
  [@bs.send]
  external getShaderInfoLog: (~context: contextT, shaderT) => string =
    "getShaderInfoLog";
  [@bs.send]
  external getProgramInfoLog: (~context: contextT, programT) => string =
    "getProgramInfoLog";
  [@bs.send]
  external getShaderSource: (~context: contextT, shaderT) => string =
    "getShaderSource";
  [@bs.send]
  external drawArrays:
    (~context: contextT, ~mode: int, ~first: int, ~count: int) => unit =
    "drawArrays";
  [@bs.send]
  external drawElements:
    (~context: contextT, ~mode: int, ~count: int, ~type_: int, ~offset: int) =>
    unit =
    "drawElements";
  [@bs.send]
  external drawElementsInstanced:
    (
      ~context: contextT,
      ~mode: int,
      ~count: int,
      ~type_: int,
      ~indices: int,
      ~primcount: int
    ) =>
    unit =
    "drawElementsInstanced";
};
