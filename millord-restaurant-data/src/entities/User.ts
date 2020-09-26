
import { Md5 } from 'ts-md5/dist/md5'


export abstract class User {
  private _id?: string;
  private _name?: string;
  private _lastName?: string;
  private _age?: number;
  private _identification?: number;
  private _phone?: string;
  private _address?: string

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

  get lastName(): string | undefined {
    return this._lastName
  }

  set lastName(value: string | undefined) {
    this._lastName = value
  }

  get age(): number | undefined {
    return this._age
  }

  set age(value: number | undefined) {
    this._age = value
  }

  get identification(): number | undefined {
    return this._identification
  }

  set identification(value: number | undefined) {
    this._identification = value
  }

  get phone(): string | undefined {
    return this._phone
  }

  set phone(value: string | undefined) {
    this._phone = value
  }

  get address(): string | undefined {
    return this._address
  }

  set address(value: string | undefined) {
    this._address = value
  }



}

