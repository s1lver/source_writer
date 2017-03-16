object Object_form: TObject_form
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1052#1086#1076#1091#1083#1080' '#1080' '#1086#1073#1098#1077#1082#1090#1099
  ClientHeight = 208
  ClientWidth = 399
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
  object AdvTabSet1: TAdvTabSet
    Left = 0
    Top = 187
    Width = 399
    Height = 21
    Version = '1.7.1.3'
    Align = alBottom
    ActiveFont.Charset = DEFAULT_CHARSET
    ActiveFont.Color = clWindowText
    ActiveFont.Height = -11
    ActiveFont.Name = 'Tahoma'
    ActiveFont.Style = []
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    AdvTabs = <
      item
        Caption = #1054#1073#1098#1077#1082#1090#1099
        Enable = True
        Visible = True
        ShowClose = False
        TabColor = clWindow
        TabColorTo = clNone
        ImageIndex = 0
        Tag = 0
      end
      item
        Caption = #1052#1086#1076#1091#1083#1080
        Enable = True
        Visible = True
        ShowClose = False
        TabColor = clWindow
        TabColorTo = clNone
        ImageIndex = 0
        Tag = 0
      end>
    FreeOnClose = False
    GradientDirection = gdVertical
    TabMargin.LeftMargin = 2
    TabMargin.TopMargin = 2
    TabMargin.RightMargin = 0
    TabOverlap = 0
    TabIndex = 0
    OnChange = AdvTabSet1Change
  end
  object ListBox1: TListBox
    Left = 0
    Top = 0
    Width = 399
    Height = 187
    Align = alClient
    ItemHeight = 13
    Items.Strings = (
      '')
    PopupMenu = PopupMenu1
    TabOrder = 1
  end
  object ListBox2: TListBox
    Left = 0
    Top = 0
    Width = 399
    Height = 187
    Align = alClient
    ItemHeight = 13
    Items.Strings = (
      '')
    PopupMenu = PopupMenu2
    TabOrder = 2
    OnDblClick = ListBox2DblClick
  end
  object PopupMenu1: TPopupMenu
    Left = 312
    Top = 128
    object N1: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1084#1086#1076#1091#1083#1100
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1084#1086#1076#1091#1083#1100
      OnClick = N2Click
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1052#1086#1076#1091#1083#1080'|*.dll'
    Left = 312
    Top = 72
  end
  object OpenDialog2: TOpenDialog
    Filter = #1054#1073#1098#1077#1082#1090#1099'|*.exe'
    Left = 312
    Top = 16
  end
  object PopupMenu2: TPopupMenu
    Left = 240
    Top = 128
    object N3: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1073#1098#1077#1082#1090
      OnClick = N3Click
    end
    object N4: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1086#1073#1098#1077#1082#1090
      OnClick = N4Click
    end
  end
end
