import { MeasureUnit } from './MeasureUnit'
import { Md5 } from 'ts-md5/dist/md5'


export class Product {
<<<<<<< HEAD
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

=======
  private id?: string;
  private name?: string;
  private price?: number;
  private measureUnit?: MeasureUnit

  constructor() { }

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

  public getPrice(): number | undefined {
    return this.price;
  }

  public setPrice(price: number): void {
    this.price = price;
  }

  public getMeasureUnit(): MeasureUnit | undefined {
    return this.measureUnit;
  }

  public setMeasureUnit(measureUnit: MeasureUnit): void {
    this.measureUnit = measureUnit;
  }


  public hashCode() {
    return Md5.hashStr(this.id)
  }


>>>>>>> e5e309a229e3d2976167e70c766c15802cac1c9b
}