"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.StockProduct = void 0;
var StockProduct = /** @class */ (function () {
    function StockProduct() {
    }
    Object.defineProperty(StockProduct.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(StockProduct.prototype, "stock", {
        get: function () {
            return this._stock;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(StockProduct.prototype, "product", {
        get: function () {
            return this._product;
        },
        set: function (value) {
            this._product = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(StockProduct.prototype, "quantity", {
        get: function () {
            return this._quantity;
        },
        set: function (value) {
            this._quantity;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(StockProduct.prototype, "measureUnit", {
        get: function () {
            return this._measureUnit;
        },
        set: function (value) {
            this._measureUnit = value;
        },
        enumerable: false,
        configurable: true
    });
    return StockProduct;
}());
exports.StockProduct = StockProduct;
