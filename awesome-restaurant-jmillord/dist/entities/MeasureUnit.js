"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.MeasureUnit = void 0;
var MeasureUnit = /** @class */ (function () {
    function MeasureUnit() {
    }
    Object.defineProperty(MeasureUnit.prototype, "id", {
        get: function () {
            return this._id;
        },
        set: function (value) {
            this._id = value;
        },
        enumerable: false,
        configurable: true
    });
    Object.defineProperty(MeasureUnit.prototype, "name", {
        get: function () {
            return this._name;
        },
        set: function (value) {
            this._name = value;
        },
        enumerable: false,
        configurable: true
    });
    return MeasureUnit;
}());
exports.MeasureUnit = MeasureUnit;
