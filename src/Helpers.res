type canvasT
@bs.set external setHiddenRAFID: ('a, int) => unit = "__hiddenrafid"
@bs.get external getButton: 'eventT => int = "button"
@bs.get external getClientX: 'eventT => int = "clientX"
@bs.get external getClientY: 'eventT => int = "clientY"
@bs.get
external getChangedTouches: 'eventT => 'touchListT = "changedTouches"
@bs.val
external convertToArray: 'notarray => array<'thing> = "Array.prototype.slice.call"
@bs.get external getTouchIdentifier: 'touchT => int = "identifier"
@bs.send external preventDefault: 'eventT => unit = "preventDefault"
@bs.get external getWhich: 'eventT => int = "which"
@bs.send
external getBoundingClientRect: canvasT => 'leftAndTop = "getBoundingClientRect"
@bs.get external getTop: 'a => int = "top"
@bs.get external getLeft: 'a => int = "left"
let getTouch0 = (e, canvas) => {
  let touches = convertToArray(getChangedTouches(e))
  switch touches {
  | [t] =>
    let rect = getBoundingClientRect(canvas)
    let x = getClientX(t) - getLeft(rect)
    let y = getClientY(t) - getTop(rect)
    Some((getTouchIdentifier(t), x, y))
  | _ => None
  }
}
@bs.get external getCanvasWidth: canvasT => int = "width"
@bs.get external getCanvasHeight: canvasT => int = "height"
@bs.set external setWidth: (canvasT, int) => unit = "width"
@bs.set external setHeight: (canvasT, int) => unit = "height"
@bs.val external createElement: string => canvasT = "document.createElement"
let createCanvas = () => createElement("canvas")
@bs.val external addToBody: canvasT => unit = "document.body.appendChild"
@bs.send
external getContext: (canvasT, string, 'options) => 'context = "getContext"
type styleT
@bs.get external getStyle: canvasT => styleT = "style"
@bs.set external setWidthStyle: (styleT, string) => unit = "width"
@bs.set external setHeightStyle: (styleT, string) => unit = "height"
@bs.set
external setBackgroundColor: (styleT, string) => unit = "backgroundColor"
type httpRequestT
@bs.new external makeXMLHttpRequest: unit => httpRequestT = "XMLHttpRequest"
@bs.send
external openFile: (httpRequestT, ~kind: string, ~filename: string, ~whatIsThis: bool) => unit =
  "open"
@bs.set
external onreadystatechange: (httpRequestT, unit => unit) => unit = "onreadystatechange"
@bs.set
external setResponseType: (httpRequestT, string) => unit = "responseType"
@bs.get external getReadyState: httpRequestT => int = "readyState"
@bs.get external getStatus: httpRequestT => int = "status"
@bs.get external getResponseText: httpRequestT => string = "responseText"
type arrayBufferT
type soundT
type audioContextT
type audioLocT
type audioGainT
let makeAudioContext: unit => audioContextT = %bs.raw(
  ` function(_) { return new (window.AudioContext || window.webkitAudioContext)(); } `
)
@bs.get external getResponse: httpRequestT => arrayBufferT = "response"
@bs.send
external decodeAudioData: (audioContextT, arrayBufferT, soundT => unit) => unit = "decodeAudioData"
@bs.send
external createBufferSource: audioContextT => audioLocT = "createBufferSource"
@bs.send external createGain: audioContextT => audioLocT = "createGain"
@bs.get external getGain: 'a => audioGainT = "gain"
@bs.set external setGainValue: (audioGainT, float) => unit = "value"
@bs.set
external setAudioSourceBuffer: (audioLocT, soundT) => unit = "buffer"
@bs.get
external getAudioContextDestination: audioContextT => audioLocT = "destination"
@bs.send
external audioSourceConnect: (audioLocT, audioLocT) => unit = "connect"
@bs.send external audioSourceStart: (audioLocT, float) => unit = "start"
@bs.set external setAudioSourceLoop: (audioLocT, bool) => unit = "loop"
@bs.send external sendRequest: (httpRequestT, Js.null<'a>) => unit = "send"
