object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1055#1077#1088#1077#1081#1090#1080'...'
  ClientHeight = 40
  ClientWidth = 272
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Edit1: TEdit
    Left = 8
    Top = 8
    Width = 142
    Height = 21
    TabOrder = 0
  end
  object BitBtn1: TBitBtn
    Left = 156
    Top = 8
    Width = 105
    Height = 25
    Caption = #1055#1077#1088#1077#1081#1090#1080
    DoubleBuffered = True
    ParentDoubleBuffered = False
    TabOrder = 1
    OnClick = BitBtn1Click
  end
end
