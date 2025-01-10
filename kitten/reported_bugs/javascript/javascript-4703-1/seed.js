



let a = new Float64Array(15);
Object.defineProperty(a, "length", {
  get: function () {
    return 6;
  }
});
delete a.__proto__.__proto__[Symbol.iterator];
Float64Array.from(a);
