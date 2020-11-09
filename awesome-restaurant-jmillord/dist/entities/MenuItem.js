"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.MenuItem = void 0;
var MenuItem = /** @class */ (function () {
    function MenuItem() {
    }
    Object.defineProperty(MenuItem.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(MenuItem.prototype, "menu", {
        get: function () {
            return this._menu;
        },
        set: function (value) {
            this._menu = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(MenuItem.prototype, "finalProduct", {
        get: function () {
            return this._finalProduct;
        },
        set: function (value) {
            this._finalProduct = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(MenuItem.prototype, "price", {
        get: function () {
            return this._price;
        },
        set: function (value) {
            this._price = value;
        },
        enumerable: false,
        configurable: true
    });
    return MenuItem;
}());
exports.MenuItem = MenuItem;
