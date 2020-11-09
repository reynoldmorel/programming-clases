"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Stock = void 0;
var Stock = /** @class */ (function () {
    function Stock() {
    }
    Object.defineProperty(Stock.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Stock.prototype, "name", {
        get: function () {
            return this._name;
        },
        set: function (value) {
            this._name = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(Stock.prototype, "stockProducts", {
        get: function () {
            return this._stockProducts;
        },
        set: function (value) {
            this._stockProducts = value;
        },
        enumerable: false,
        configurable: true
    });
    return Stock;
}());
exports.Stock = Stock;
