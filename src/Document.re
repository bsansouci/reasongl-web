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
