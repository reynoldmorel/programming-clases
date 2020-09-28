
import { StockProduct } from './StockProduct'

import { Md5 } from 'ts-md5/dist/md5'

export class Stock {
<<<<<<< HEAD
  private _id?: string;
  private _name?: string;
  private _stockProducts?: Array<StockProduct>
=======
  private id?: string;
  private name?: string;
  private stockProducts?: Array<StockProduct>
>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b

  constructor() {
  }

<<<<<<< HEAD

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


=======
  public getId(): string | undefined {
    return this.id;
  }

  public setId(id: string): void {
    this.id = id;
  }

  public getName(): string | undefined {
    return this.name;
  }

  public setName(name: string): void {
    this.name = name;
  }

  public getStockProducts(): Array<StockProduct> | undefined {
    return this.stockProducts;
  }

  public setStockProducts(stockProducts: Array<StockProduct>): void {
    this.stockProducts = stockProducts;
  }

  public hashCode() {
    return Md5.hashStr(this.id)
  }



>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
}