import { MeasureUnit } from './MeasureUnit'
import { Md5 } from 'ts-md5/dist/md5'


export class Product {
  private _id?: string;
  private _name?: string;
  private _price?: number;
  private _measureUnit?: MeasureUnit

  constructor() { }

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
    this.name = value
  }

  get price(): number | undefined {
    return this._price
  }

  set price(value: number | undefined) {
    this.price = value
  }

  get measureUnit(): MeasureUnit | undefined {
    return this._measureUnit
  }

  set measureUnit(value: MeasureUnit | undefined) {
    this._measureUnit = value
  }

}