"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Menu = void 0;
var Menu = /** @class */ (function () {
    function Menu() {
    }
    Object.defineProperty(Menu.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Menu.prototype, "name", {
        get: function () {
            return this._name;
        },
        set: function (value) {
            this._name = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Menu.prototype, "finalProducts", {
        get: function () {
            return this._finalProducts;
        },
        set: function (value) {
            this._finalProducts = value;
        },
        enumerable: false,
        configurable: true
    });
    return Menu;
}());
exports.Menu = Menu;
