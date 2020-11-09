import { Stock } from './Stock'
import { Product } from './Product'
import { MeasureUnit } from './MeasureUnit'


import { Md5 } from 'ts-md5/dist/md5'

export class StockProduct {

  private _id?: string;
  private _stock?: Stock;
  private _product?: Product
  private _quantity?: number;
  private _measureUnit?: MeasureUnit

  constructor() { }

  get id(): string | undefined {
    return this._id
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get stock(): Stock | undefined {
    return this._stock
  }

  get product(): Product | undefined {
    return this._product

  }
  set product(value: Product | undefined) {
    this._product = value
  }

  get quantity(): number | undefined {
    return this._quantity
  }

  set quantity(value: number | undefined) {
    this._quantity
  }

  get measureUnit(): MeasureUnit | undefined {
    return this._measureUnit
  }

  set measureUnit(value: MeasureUnit | undefined) {
    this._measureUnit = value
  }


}