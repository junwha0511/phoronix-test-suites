(self.AMP=self.AMP||[]).push({n:"amp-fit-text",ev:"0.1",l:true,v:"2108100143000",m:1,f:function(AMP,_){function h(a){let b=parseFloat(a);return"number"===typeof b&&isFinite(b)?b:void 0}let l;let m="Webkit webkit Moz moz ms O o".split(" ");function n(a,b,c){if(b.startsWith("--"))return b;l||(l=Object.create(null));let d=l[b];if(!d||c){d=b;if(void 0===a[b]){var e=b.charAt(0).toUpperCase()+b.slice(1);a:{for(let f=0;f<m.length;f++){let k=m[f]+e;if(void 0!==a[k]){e=k;break a}}e=""}let g=e;void 0!==a[g]&&(d=g)}c||(l[b]=d)}return d}function p(a,b,c){(b=n(a.style,b,void 0))&&(b.startsWith("--")?a.style.setProperty(b,c):a.style[b]=c)}
/* https://mths.be/cssescape v1.5.1 by @mathias | MIT license */
function q(a,b){let c=[];for(a=a.firstChild;a;a=a.nextSibling)b(a)&&c.push(a);return c}function r(a){return q(a,(b=>{{let c;"string"==typeof b?c=b:b.nodeType===Node.ELEMENT_NODE&&(c=b.tagName);b=c&&c.toLowerCase().startsWith("i-")?!0:b.nodeType!==Node.ELEMENT_NODE?!1:b.hasAttribute("placeholder")||b.hasAttribute("fallback")||b.hasAttribute("overflow")}return!b}))}function t(a,b){function c(f){g=null;e=a.setTimeout(d,100);b.apply(null,f)}function d(){e=0;g&&c(g)}let e=0,g=null;return function(...f){e?g=f:c(f)}}function u(a){let b=a.o.offsetHeight;var c=a.j;var d=a.o.offsetWidth;var e=a.C,g=a.B;for(g++;1<g-e;){let f=Math.floor((e+g)/2);p(c,"fontSize",`${f}px`);let k=c.offsetWidth;c.offsetHeight>b||k>d?g=f:e=f}d=e;p(a.h,"fontSize",`${d}px`);c=a.h;a=a.j;p(a,"fontSize",`${d}px`);a=a.offsetHeight>b;d*=1.15;e=Math.floor(b/d);c.classList.toggle("i-amphtml-fit-text-content-overflown",a);a={lineClamp:a?e:"",maxHeight:a?`${d*e}px`:""};for(let f in a)p(c,f,a[f])}class v extends AMP.BaseElement{static prerenderAllowed(){return!0}constructor(a){super(a);this.j=this.h=this.o=null;this.B=this.C=-1;this.A=null;this.D=""}isLayoutSupported(a){return"fixed"==a||"fixed-height"==a||"responsive"==a||"fill"==a||"flex-item"==a||"fluid"==a||"intrinsic"==a}buildCallback(){let a=this.element,{content:b,contentWrapper:c,measurer:d}=w(a);this.o=b;this.h=c;this.j=d;this.C=h(a.getAttribute("min-font-size"))||6;this.B=h(a.getAttribute("max-font-size"))||72;Object.defineProperty(this.element,"textContent",{set:e=>{this.D=e;this.mutateElement((()=>{this.h.textContent=e;x(this.h,this.j);u(this)}))},get:()=>this.D||this.h.textContent})}isRelayoutNeeded(){return!0}layoutCallback(){if(this.win.ResizeObserver&&null===this.A){let a=new this.win.ResizeObserver(t(this.win,(()=>this.mutateElement((()=>{x(this.h,this.j);u(this)})))));a.observe(this.o);a.observe(this.j);this.A=function(){a.disconnect()}}return this.mutateElement((()=>{u(this);var a={visibility:"visible"};let b=this.o.style;for(let c in a)b.setProperty(n(b,c),String(a[c]),"important")}))}unlayoutCallback(){null!==this.A&&(this.A(),this.A=null)}}function w(a){var b=a.ownerDocument;let c=b.createElement("div");c.classList.add("i-amphtml-fill-content");c.classList.add("i-amphtml-fit-text-content");let d=b.createElement("div");d.classList.add("i-amphtml-fit-text-content-wrapper");c.appendChild(d);b=b.createElement("div");b.classList.add("i-amphtml-fit-text-measurer");r(a).forEach((e=>d.appendChild(e)));x(d,b);a.appendChild(c);a.appendChild(b);return{content:c,contentWrapper:d,measurer:b}}function x(a,b){for(;b.firstChild;)b.removeChild(b.firstChild);let c=b.ownerDocument.createDocumentFragment();for(a=a.firstChild;a;a=a.nextSibling)c.appendChild(a.cloneNode(!0));b.appendChild(c)}(a=>{a.registerElement("amp-fit-text",v,".i-amphtml-fit-text-content,.i-amphtml-fit-text-content.i-amphtml-fill-content{display:block;display:-ms-flexbox;display:flex;-ms-flex-direction:column;flex-direction:column;-ms-flex-wrap:nowrap;flex-wrap:nowrap;-ms-flex-pack:center;justify-content:center}.i-amphtml-fit-text-content{z-index:2!important;visibility:hidden!important}.i-amphtml-fit-text-content-wrapper{line-height:1.15em!important}.i-amphtml-fit-text-content-overflown{display:block;display:-webkit-box;-webkit-box-orient:vertical;overflow:hidden}.i-amphtml-fit-text-measurer{position:absolute!important;top:0!important;left:0!important;z-index:1!important;visibility:hidden!important;line-height:1.15em!important}\n/*# sourceURL=/extensions/amp-fit-text/0.1/amp-fit-text.css*/")})(self.AMP)}});//# sourceMappingURL=amp-fit-text-0.1.mjs.map