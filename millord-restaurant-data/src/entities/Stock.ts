
import { StockProduct } from './StockProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class Stock {
  private _id?: string;
  private _name?: string;
  private _stockProducts?: Array<StockProduct>

  constructor() {
  }


  get id(): string | undefined {
    return this._id
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get name(): string | undefined {
    return this._name
  }

  set name(value: string | undefined) {
    this._name = value
  }

  get stockProducts(): Array<StockProduct> | undefined {
    return this._stockProducts
  }

  set stockProducts(value: Array<StockProduct> | undefined) {
    this._stockProducts = value
  }


}