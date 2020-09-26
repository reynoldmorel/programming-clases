import { FinalProduct } from './FinalProduct'
import { MenuItem } from './MenuItem'

import { Md5 } from 'ts-md5/dist/md5'


export class Menu {
  private _id?: string;
  private _name?: string;
  private _finalProducts?: Array<MenuItem>

  constructor() { }

  get id(): string | undefined {
    return this._id;
  }

  set id(value: string | undefined) {
    this._id = value
  }

  get name(): string | undefined {
    return this._name;
  }

  set name(value: string | undefined) {
    this._name = value;
  }

  get finalProducts(): Array<MenuItem> | undefined {
    return this._finalProducts
  }

  set finalProducts(value: Array<MenuItem> | undefined) {
    this._finalProducts = value
  }


}