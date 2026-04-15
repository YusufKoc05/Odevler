#define MyAppName "NeoSnake"
#define MyAppVersion "1.0.0"
#define MyAppPublisher "Yusuf Koc"
#define MyAppExeName "NeoSnake_Release.exe"
#define MyAppPckName "NeoSnake_Release.pck"

[Setup]
AppId={{A4D6A4C2-2A51-4F6F-91C3-8B58D2E6A101}
AppName={#MyAppName}
AppVersion={#MyAppVersion}
AppPublisher={#MyAppPublisher}
DefaultDirName={autopf}\{#MyAppName}
DefaultGroupName={#MyAppName}
UninstallDisplayIcon={app}\{#MyAppExeName}
OutputDir=output
OutputBaseFilename=NeoSnake_Setup
Compression=lzma
SolidCompression=yes
WizardStyle=modern
PrivilegesRequired=admin
ArchitecturesAllowed=x64compatible
ArchitecturesInstallIn64BitMode=x64compatible

[Languages]
Name: "turkish"; MessagesFile: "compiler:Languages\Turkish.isl"

[Tasks]
Name: "desktopicon"; Description: "Masaüstü kısayolu oluştur"; Flags: unchecked

[Files]
Source: "C:\NeoSnakeBuild\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "C:\NeoSnakeBuild\{#MyAppPckName}"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{autoprograms}\{#MyAppName}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{autodesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: "{app}\{#MyAppExeName}"; Description: "NeoSnake'i başlat"; Flags: nowait postinstall skipifsilent

[Code]
const
  MarkerRegKey = 'Software\NeoSnake';
  MarkerValue = 'InstallMarker';
  DeviceValue = 'DeviceId';
  InstallTimeValue = 'InstalledAt';

function GetMachineGuid(): string;
begin
  if not RegQueryStringValue(HKLM, 'SOFTWARE\Microsoft\Cryptography', 'MachineGuid', Result) then
    Result := 'UNKNOWN_DEVICE';
  Result := Trim(Result);
end;

function AlreadyInstalled(): Boolean;
var
  Marker: string;
begin
  Result := RegQueryStringValue(HKLM, MarkerRegKey, MarkerValue, Marker) and (Trim(Marker) <> '');
end;

function InitializeSetup(): Boolean;
begin
  Result := True;

  if AlreadyInstalled() then
  begin
    MsgBox(
      'Bu bilgisayarda NeoSnake daha önce kurulmuş.' + #13#10#13#10 +
      'Bu kurulum paketi yalnızca bir kez kurulacak şekilde ayarlandı.' + #13#10 +
      'Program kaldırılsa bile cihaz işareti saklanır.',
      mbError, MB_OK);
    Result := False;
  end;
end;

procedure WriteInstallMarker();
begin
  RegWriteStringValue(HKLM, MarkerRegKey, MarkerValue, 'INSTALLED');
  RegWriteStringValue(HKLM, MarkerRegKey, DeviceValue, GetMachineGuid());
  RegWriteStringValue(HKLM, MarkerRegKey, InstallTimeValue, GetDateTimeString('yyyy-mm-dd hh:nn:ss', '-', ':'));
end;

procedure CurStepChanged(CurStep: TSetupStep);
begin
  if CurStep = ssPostInstall then
    WriteInstallMarker();
end;