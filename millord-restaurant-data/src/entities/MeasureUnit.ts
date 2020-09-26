import { Md5 } from 'ts-md5/dist/md5'



export class MeasureUnit {
  private _id?: string;
  private _name?: string;
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


}