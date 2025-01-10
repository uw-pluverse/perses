grammar Rust;

@lexer::members {
    private Token lastToken;

    public void emit(Token token) {
      lastToken = token;
      super.emit(token);
    }
}

fragment XID_Start :
      '\u0041' .. '\u005a'
    | '_'
    | '\u0061' .. '\u007a'
    | '\u00aa'
    | '\u00b5'
    | '\u00ba'
    | '\u00c0' .. '\u00d6'
    | '\u00d8' .. '\u00f6'
    | '\u00f8' .. '\u0236'
    | '\u0250' .. '\u02c1'
    | '\u02c6' .. '\u02d1'
    | '\u02e0' .. '\u02e4'
    | '\u02ee'
    | '\u0386'
    | '\u0388' .. '\u038a'
    | '\u038c'
    | '\u038e' .. '\u03a1'
    | '\u03a3' .. '\u03ce'
    | '\u03d0' .. '\u03f5'
    | '\u03f7' .. '\u03fb'
    | '\u0400' .. '\u0481'
    | '\u048a' .. '\u04ce'
    | '\u04d0' .. '\u04f5'
    | '\u04f8' .. '\u04f9'
    | '\u0500' .. '\u050f'
    | '\u0531' .. '\u0556'
    | '\u0559'
    | '\u0561' .. '\u0587'
    | '\u05d0' .. '\u05ea'
    | '\u05f0' .. '\u05f2'
    | '\u0621' .. '\u063a'
    | '\u0640' .. '\u064a'
    | '\u066e' .. '\u066f'
    | '\u0671' .. '\u06d3'
    | '\u06d5'
    | '\u06e5' .. '\u06e6'
    | '\u06ee' .. '\u06ef'
    | '\u06fa' .. '\u06fc'
    | '\u06ff'
    | '\u0710'
    | '\u0712' .. '\u072f'
    | '\u074d' .. '\u074f'
    | '\u0780' .. '\u07a5'
    | '\u07b1'
    | '\u0904' .. '\u0939'
    | '\u093d'
    | '\u0950'
    | '\u0958' .. '\u0961'
    | '\u0985' .. '\u098c'
    | '\u098f' .. '\u0990'
    | '\u0993' .. '\u09a8'
    | '\u09aa' .. '\u09b0'
    | '\u09b2'
    | '\u09b6' .. '\u09b9'
    | '\u09bd'
    | '\u09dc' .. '\u09dd'
    | '\u09df' .. '\u09e1'
    | '\u09f0' .. '\u09f1'
    | '\u0a05' .. '\u0a0a'
    | '\u0a0f' .. '\u0a10'
    | '\u0a13' .. '\u0a28'
    | '\u0a2a' .. '\u0a30'
    | '\u0a32' .. '\u0a33'
    | '\u0a35' .. '\u0a36'
    | '\u0a38' .. '\u0a39'
    | '\u0a59' .. '\u0a5c'
    | '\u0a5e'
    | '\u0a72' .. '\u0a74'
    | '\u0a85' .. '\u0a8d'
    | '\u0a8f' .. '\u0a91'
    | '\u0a93' .. '\u0aa8'
    | '\u0aaa' .. '\u0ab0'
    | '\u0ab2' .. '\u0ab3'
    | '\u0ab5' .. '\u0ab9'
    | '\u0abd'
    | '\u0ad0'
    | '\u0ae0' .. '\u0ae1'
    | '\u0b05' .. '\u0b0c'
    | '\u0b0f' .. '\u0b10'
    | '\u0b13' .. '\u0b28'
    | '\u0b2a' .. '\u0b30'
    | '\u0b32' .. '\u0b33'
    | '\u0b35' .. '\u0b39'
    | '\u0b3d'
    | '\u0b5c' .. '\u0b5d'
    | '\u0b5f' .. '\u0b61'
    | '\u0b71'
    | '\u0b83'
    | '\u0b85' .. '\u0b8a'
    | '\u0b8e' .. '\u0b90'
    | '\u0b92' .. '\u0b95'
    | '\u0b99' .. '\u0b9a'
    | '\u0b9c'
    | '\u0b9e' .. '\u0b9f'
    | '\u0ba3' .. '\u0ba4'
    | '\u0ba8' .. '\u0baa'
    | '\u0bae' .. '\u0bb5'
    | '\u0bb7' .. '\u0bb9'
    | '\u0c05' .. '\u0c0c'
    | '\u0c0e' .. '\u0c10'
    | '\u0c12' .. '\u0c28'
    | '\u0c2a' .. '\u0c33'
    | '\u0c35' .. '\u0c39'
    | '\u0c60' .. '\u0c61'
    | '\u0c85' .. '\u0c8c'
    | '\u0c8e' .. '\u0c90'
    | '\u0c92' .. '\u0ca8'
    | '\u0caa' .. '\u0cb3'
    | '\u0cb5' .. '\u0cb9'
    | '\u0cbd'
    | '\u0cde'
    | '\u0ce0' .. '\u0ce1'
    | '\u0d05' .. '\u0d0c'
    | '\u0d0e' .. '\u0d10'
    | '\u0d12' .. '\u0d28'
    | '\u0d2a' .. '\u0d39'
    | '\u0d60' .. '\u0d61'
    | '\u0d85' .. '\u0d96'
    | '\u0d9a' .. '\u0db1'
    | '\u0db3' .. '\u0dbb'
    | '\u0dbd'
    | '\u0dc0' .. '\u0dc6'
    | '\u0e01' .. '\u0e30'
    | '\u0e32'
    | '\u0e40' .. '\u0e46'
    | '\u0e81' .. '\u0e82'
    | '\u0e84'
    | '\u0e87' .. '\u0e88'
    | '\u0e8a'
    | '\u0e8d'
    | '\u0e94' .. '\u0e97'
    | '\u0e99' .. '\u0e9f'
    | '\u0ea1' .. '\u0ea3'
    | '\u0ea5'
    | '\u0ea7'
    | '\u0eaa' .. '\u0eab'
    | '\u0ead' .. '\u0eb0'
    | '\u0eb2'
    | '\u0ebd'
    | '\u0ec0' .. '\u0ec4'
    | '\u0ec6'
    | '\u0edc' .. '\u0edd'
    | '\u0f00'
    | '\u0f40' .. '\u0f47'
    | '\u0f49' .. '\u0f6a'
    | '\u0f88' .. '\u0f8b'
    | '\u1000' .. '\u1021'
    | '\u1023' .. '\u1027'
    | '\u1029' .. '\u102a'
    | '\u1050' .. '\u1055'
    | '\u10a0' .. '\u10c5'
    | '\u10d0' .. '\u10f8'
    | '\u1100' .. '\u1159'
    | '\u115f' .. '\u11a2'
    | '\u11a8' .. '\u11f9'
    | '\u1200' .. '\u1206'
    | '\u1208' .. '\u1246'
    | '\u1248'
    | '\u124a' .. '\u124d'
    | '\u1250' .. '\u1256'
    | '\u1258'
    | '\u125a' .. '\u125d'
    | '\u1260' .. '\u1286'
    | '\u1288'
    | '\u128a' .. '\u128d'
    | '\u1290' .. '\u12ae'
    | '\u12b0'
    | '\u12b2' .. '\u12b5'
    | '\u12b8' .. '\u12be'
    | '\u12c0'
    | '\u12c2' .. '\u12c5'
    | '\u12c8' .. '\u12ce'
    | '\u12d0' .. '\u12d6'
    | '\u12d8' .. '\u12ee'
    | '\u12f0' .. '\u130e'
    | '\u1310'
    | '\u1312' .. '\u1315'
    | '\u1318' .. '\u131e'
    | '\u1320' .. '\u1346'
    | '\u1348' .. '\u135a'
    | '\u13a0' .. '\u13f4'
    | '\u1401' .. '\u166c'
    | '\u166f' .. '\u1676'
    | '\u1681' .. '\u169a'
    | '\u16a0' .. '\u16ea'
    | '\u16ee' .. '\u16f0'
    | '\u1700' .. '\u170c'
    | '\u170e' .. '\u1711'
    | '\u1720' .. '\u1731'
    | '\u1740' .. '\u1751'
    | '\u1760' .. '\u176c'
    | '\u176e' .. '\u1770'
    | '\u1780' .. '\u17b3'
    | '\u17d7'
    | '\u17dc'
    | '\u1820' .. '\u1877'
    | '\u1880' .. '\u18a8'
    | '\u1900' .. '\u191c'
    | '\u1950' .. '\u196d'
    | '\u1970' .. '\u1974'
    | '\u1d00' .. '\u1d6b'
    | '\u1e00' .. '\u1e9b'
    | '\u1ea0' .. '\u1ef9'
    | '\u1f00' .. '\u1f15'
    | '\u1f18' .. '\u1f1d'
    | '\u1f20' .. '\u1f45'
    | '\u1f48' .. '\u1f4d'
    | '\u1f50' .. '\u1f57'
    | '\u1f59'
    | '\u1f5b'
    | '\u1f5d'
    | '\u1f5f' .. '\u1f7d'
    | '\u1f80' .. '\u1fb4'
    | '\u1fb6' .. '\u1fbc'
    | '\u1fbe'
    | '\u1fc2' .. '\u1fc4'
    | '\u1fc6' .. '\u1fcc'
    | '\u1fd0' .. '\u1fd3'
    | '\u1fd6' .. '\u1fdb'
    | '\u1fe0' .. '\u1fec'
    | '\u1ff2' .. '\u1ff4'
    | '\u1ff6' .. '\u1ffc'
    | '\u2071'
    | '\u207f'
    | '\u2102'
    | '\u2107'
    | '\u210a' .. '\u2113'
    | '\u2115'
    | '\u2118' .. '\u211d'
    | '\u2124'
    | '\u2126'
    | '\u2128'
    | '\u212a' .. '\u2131'
    | '\u2133' .. '\u2139'
    | '\u213d' .. '\u213f'
    | '\u2145' .. '\u2149'
    | '\u2160' .. '\u2183'
    | '\u3005' .. '\u3007'
    | '\u3021' .. '\u3029'
    | '\u3031' .. '\u3035'
    | '\u3038' .. '\u303c'
    | '\u3041' .. '\u3096'
    | '\u309d' .. '\u309f'
    | '\u30a1' .. '\u30fa'
    | '\u30fc' .. '\u30ff'
    | '\u3105' .. '\u312c'
    | '\u3131' .. '\u318e'
    | '\u31a0' .. '\u31b7'
    | '\u31f0' .. '\u31ff'
    | '\u3400' .. '\u4db5'
    | '\u4e00' .. '\u9fa5'
    | '\ua000' .. '\ua48c'
    | '\uac00' .. '\ud7a3'
    | '\uf900' .. '\ufa2d'
    | '\ufa30' .. '\ufa6a'
    | '\ufb00' .. '\ufb06'
    | '\ufb13' .. '\ufb17'
    | '\ufb1d'
    | '\ufb1f' .. '\ufb28'
    | '\ufb2a' .. '\ufb36'
    | '\ufb38' .. '\ufb3c'
    | '\ufb3e'
    | '\ufb40' .. '\ufb41'
    | '\ufb43' .. '\ufb44'
    | '\ufb46' .. '\ufbb1'
    | '\ufbd3' .. '\ufc5d'
    | '\ufc64' .. '\ufd3d'
    | '\ufd50' .. '\ufd8f'
    | '\ufd92' .. '\ufdc7'
    | '\ufdf0' .. '\ufdf9'
    | '\ufe71'
    | '\ufe73'
    | '\ufe77'
    | '\ufe79'
    | '\ufe7b'
    | '\ufe7d'
    | '\ufe7f' .. '\ufefc'
    | '\uff21' .. '\uff3a'
    | '\uff41' .. '\uff5a'
    | '\uff66' .. '\uff9d'
    | '\uffa0' .. '\uffbe'
    | '\uffc2' .. '\uffc7'
    | '\uffca' .. '\uffcf'
    | '\uffd2' .. '\uffd7'
    | '\uffda' .. '\uffdc'
    | '\ud800' '\udc00' .. '\udc0a'
    | '\ud800' '\udc0d' .. '\udc25'
    | '\ud800' '\udc28' .. '\udc39'
    | '\ud800' '\udc3c' .. '\udc3c'
    | '\ud800' '\udc3f' .. '\udc4c'
    | '\ud800' '\udc50' .. '\udc5c'
    | '\ud800' '\udc80' .. '\udcf9'
    | '\ud800' '\udf00' .. '\udf1d'
    | '\ud800' '\udf30' .. '\udf49'
    | '\ud800' '\udf80' .. '\udf9c'
    | '\ud801' '\ue000' .. '\ue09c'
    | '\ud802' '\ue400' .. '\ue404'
    | '\ud802' '\u0808'
    | '\ud802' '\ue40a' .. '\ue434'
    | '\ud802' '\ue437' .. '\ue437'
    | '\ud802' '\u083c'
    | '\ud802' '\u083f'
    | '\ud835' '\ub000' .. '\ub053'
    | '\ud835' '\ub056' .. '\ub09b'
    | '\ud835' '\ub09e' .. '\ub09e'
    | '\ud835' '\ud4a2'
    | '\ud835' '\ub0a5' .. '\ub0a5'
    | '\ud835' '\ub0a9' .. '\ub0ab'
    | '\ud835' '\ub0ae' .. '\ub0b8'
    | '\ud835' '\ud4bb'
    | '\ud835' '\ub0bd' .. '\ub0c2'
    | '\ud835' '\ub0c5' .. '\ub104'
    | '\ud835' '\ub107' .. '\ub109'
    | '\ud835' '\ub10d' .. '\ub113'
    | '\ud835' '\ub116' .. '\ub11b'
    | '\ud835' '\ub11e' .. '\ub138'
    | '\ud835' '\ub13b' .. '\ub13d'
    | '\ud835' '\ub140' .. '\ub143'
    | '\ud835' '\ud546'
    | '\ud835' '\ub14a' .. '\ub14f'
    | '\ud835' '\ub152' .. '\ub2a2'
    | '\ud835' '\ub2a8' .. '\ub2bf'
    | '\ud835' '\ub2c2' .. '\ub2d9'
    | '\ud835' '\ub2dc' .. '\ub2f9'
    | '\ud835' '\ub2fc' .. '\ub313'
    | '\ud835' '\ub316' .. '\ub333'
    | '\ud835' '\ub336' .. '\ub34d'
    | '\ud835' '\ub350' .. '\ub36d'
    | '\ud835' '\ub370' .. '\ub387'
    | '\ud835' '\ub38a' .. '\ub3a7'
    | '\ud835' '\ub3aa' .. '\ub3c1'
    | '\ud835' '\ub3c4' .. '\ub3c8'
    | '\ud840' '\udc00' .. '\udffe'
    | '\ud841' '\ue000' .. '\ue3fe'
    | '\ud842' '\ue400' .. '\ue7fe'
    | '\ud843' '\ue800' .. '\uebfe'
    | '\ud844' '\uec00' .. '\ueffe'
    | '\ud845' '\uf000' .. '\uf3fe'
    | '\ud846' '\uf400' .. '\uf7fe'
    | '\ud847' '\uf800' .. '\ufbfe'
    | '\ud848' '\ufc00' .. '\ufffe'
    | '\ud849' '\u0000' .. '\u03fe'
    | '\ud84a' '\u0400' .. '\u07fe'
    | '\ud84b' '\u0800' .. '\u0bfe'
    | '\ud84c' '\u0c00' .. '\u0ffe'
    | '\ud84d' '\u1000' .. '\u13fe'
    | '\ud84e' '\u1400' .. '\u17fe'
    | '\ud84f' '\u1800' .. '\u1bfe'
    | '\ud850' '\u1c00' .. '\u1ffe'
    | '\ud851' '\u2000' .. '\u23fe'
    | '\ud852' '\u2400' .. '\u27fe'
    | '\ud853' '\u2800' .. '\u2bfe'
    | '\ud854' '\u2c00' .. '\u2ffe'
    | '\ud855' '\u3000' .. '\u33fe'
    | '\ud856' '\u3400' .. '\u37fe'
    | '\ud857' '\u3800' .. '\u3bfe'
    | '\ud858' '\u3c00' .. '\u3ffe'
    | '\ud859' '\u4000' .. '\u43fe'
    | '\ud85a' '\u4400' .. '\u47fe'
    | '\ud85b' '\u4800' .. '\u4bfe'
    | '\ud85c' '\u4c00' .. '\u4ffe'
    | '\ud85d' '\u5000' .. '\u53fe'
    | '\ud85e' '\u5400' .. '\u57fe'
    | '\ud85f' '\u5800' .. '\u5bfe'
    | '\ud860' '\u5c00' .. '\u5ffe'
    | '\ud861' '\u6000' .. '\u63fe'
    | '\ud862' '\u6400' .. '\u67fe'
    | '\ud863' '\u6800' .. '\u6bfe'
    | '\ud864' '\u6c00' .. '\u6ffe'
    | '\ud865' '\u7000' .. '\u73fe'
    | '\ud866' '\u7400' .. '\u77fe'
    | '\ud867' '\u7800' .. '\u7bfe'
    | '\ud868' '\u7c00' .. '\u7ffe'
    | '\ud869' '\u8000' .. '\u82d5'
    | '\ud87e' '\ud400' .. '\ud61c'
    ;

fragment XID_Continue:
      '\u0030' .. '\u0039'
    | '\u0041' .. '\u005a'
    | '\u005f'
    | '\u0061' .. '\u007a'
    | '\u00aa'
    | '\u00b5'
    | '\u00b7'
    | '\u00ba'
    | '\u00c0' .. '\u00d6'
    | '\u00d8' .. '\u00f6'
    | '\u00f8' .. '\u0236'
    | '\u0250' .. '\u02c1'
    | '\u02c6' .. '\u02d1'
    | '\u02e0' .. '\u02e4'
    | '\u02ee'
    | '\u0300' .. '\u0357'
    | '\u035d' .. '\u036f'
    | '\u0386'
    | '\u0388' .. '\u038a'
    | '\u038c'
    | '\u038e' .. '\u03a1'
    | '\u03a3' .. '\u03ce'
    | '\u03d0' .. '\u03f5'
    | '\u03f7' .. '\u03fb'
    | '\u0400' .. '\u0481'
    | '\u0483' .. '\u0486'
    | '\u048a' .. '\u04ce'
    | '\u04d0' .. '\u04f5'
    | '\u04f8' .. '\u04f9'
    | '\u0500' .. '\u050f'
    | '\u0531' .. '\u0556'
    | '\u0559'
    | '\u0561' .. '\u0587'
    | '\u0591' .. '\u05a1'
    | '\u05a3' .. '\u05b9'
    | '\u05bb' .. '\u05bd'
    | '\u05bf'
    | '\u05c1' .. '\u05c2'
    | '\u05c4'
    | '\u05d0' .. '\u05ea'
    | '\u05f0' .. '\u05f2'
    | '\u0610' .. '\u0615'
    | '\u0621' .. '\u063a'
    | '\u0640' .. '\u0658'
    | '\u0660' .. '\u0669'
    | '\u066e' .. '\u06d3'
    | '\u06d5' .. '\u06dc'
    | '\u06df' .. '\u06e8'
    | '\u06ea' .. '\u06fc'
    | '\u06ff'
    | '\u0710' .. '\u074a'
    | '\u074d' .. '\u074f'
    | '\u0780' .. '\u07b1'
    | '\u0901' .. '\u0939'
    | '\u093c' .. '\u094d'
    | '\u0950' .. '\u0954'
    | '\u0958' .. '\u0963'
    | '\u0966' .. '\u096f'
    | '\u0981' .. '\u0983'
    | '\u0985' .. '\u098c'
    | '\u098f' .. '\u0990'
    | '\u0993' .. '\u09a8'
    | '\u09aa' .. '\u09b0'
    | '\u09b2'
    | '\u09b6' .. '\u09b9'
    | '\u09bc' .. '\u09c4'
    | '\u09c7' .. '\u09c8'
    | '\u09cb' .. '\u09cd'
    | '\u09d7'
    | '\u09dc' .. '\u09dd'
    | '\u09df' .. '\u09e3'
    | '\u09e6' .. '\u09f1'
    | '\u0a01' .. '\u0a03'
    | '\u0a05' .. '\u0a0a'
    | '\u0a0f' .. '\u0a10'
    | '\u0a13' .. '\u0a28'
    | '\u0a2a' .. '\u0a30'
    | '\u0a32' .. '\u0a33'
    | '\u0a35' .. '\u0a36'
    | '\u0a38' .. '\u0a39'
    | '\u0a3c'
    | '\u0a3e' .. '\u0a42'
    | '\u0a47' .. '\u0a48'
    | '\u0a4b' .. '\u0a4d'
    | '\u0a59' .. '\u0a5c'
    | '\u0a5e'
    | '\u0a66' .. '\u0a74'
    | '\u0a81' .. '\u0a83'
    | '\u0a85' .. '\u0a8d'
    | '\u0a8f' .. '\u0a91'
    | '\u0a93' .. '\u0aa8'
    | '\u0aaa' .. '\u0ab0'
    | '\u0ab2' .. '\u0ab3'
    | '\u0ab5' .. '\u0ab9'
    | '\u0abc' .. '\u0ac5'
    | '\u0ac7' .. '\u0ac9'
    | '\u0acb' .. '\u0acd'
    | '\u0ad0'
    | '\u0ae0' .. '\u0ae3'
    | '\u0ae6' .. '\u0aef'
    | '\u0b01' .. '\u0b03'
    | '\u0b05' .. '\u0b0c'
    | '\u0b0f' .. '\u0b10'
    | '\u0b13' .. '\u0b28'
    | '\u0b2a' .. '\u0b30'
    | '\u0b32' .. '\u0b33'
    | '\u0b35' .. '\u0b39'
    | '\u0b3c' .. '\u0b43'
    | '\u0b47' .. '\u0b48'
    | '\u0b4b' .. '\u0b4d'
    | '\u0b56' .. '\u0b57'
    | '\u0b5c' .. '\u0b5d'
    | '\u0b5f' .. '\u0b61'
    | '\u0b66' .. '\u0b6f'
    | '\u0b71'
    | '\u0b82' .. '\u0b83'
    | '\u0b85' .. '\u0b8a'
    | '\u0b8e' .. '\u0b90'
    | '\u0b92' .. '\u0b95'
    | '\u0b99' .. '\u0b9a'
    | '\u0b9c'
    | '\u0b9e' .. '\u0b9f'
    | '\u0ba3' .. '\u0ba4'
    | '\u0ba8' .. '\u0baa'
    | '\u0bae' .. '\u0bb5'
    | '\u0bb7' .. '\u0bb9'
    | '\u0bbe' .. '\u0bc2'
    | '\u0bc6' .. '\u0bc8'
    | '\u0bca' .. '\u0bcd'
    | '\u0bd7'
    | '\u0be7' .. '\u0bef'
    | '\u0c01' .. '\u0c03'
    | '\u0c05' .. '\u0c0c'
    | '\u0c0e' .. '\u0c10'
    | '\u0c12' .. '\u0c28'
    | '\u0c2a' .. '\u0c33'
    | '\u0c35' .. '\u0c39'
    | '\u0c3e' .. '\u0c44'
    | '\u0c46' .. '\u0c48'
    | '\u0c4a' .. '\u0c4d'
    | '\u0c55' .. '\u0c56'
    | '\u0c60' .. '\u0c61'
    | '\u0c66' .. '\u0c6f'
    | '\u0c82' .. '\u0c83'
    | '\u0c85' .. '\u0c8c'
    | '\u0c8e' .. '\u0c90'
    | '\u0c92' .. '\u0ca8'
    | '\u0caa' .. '\u0cb3'
    | '\u0cb5' .. '\u0cb9'
    | '\u0cbc' .. '\u0cc4'
    | '\u0cc6' .. '\u0cc8'
    | '\u0cca' .. '\u0ccd'
    | '\u0cd5' .. '\u0cd6'
    | '\u0cde'
    | '\u0ce0' .. '\u0ce1'
    | '\u0ce6' .. '\u0cef'
    | '\u0d02' .. '\u0d03'
    | '\u0d05' .. '\u0d0c'
    | '\u0d0e' .. '\u0d10'
    | '\u0d12' .. '\u0d28'
    | '\u0d2a' .. '\u0d39'
    | '\u0d3e' .. '\u0d43'
    | '\u0d46' .. '\u0d48'
    | '\u0d4a' .. '\u0d4d'
    | '\u0d57'
    | '\u0d60' .. '\u0d61'
    | '\u0d66' .. '\u0d6f'
    | '\u0d82' .. '\u0d83'
    | '\u0d85' .. '\u0d96'
    | '\u0d9a' .. '\u0db1'
    | '\u0db3' .. '\u0dbb'
    | '\u0dbd'
    | '\u0dc0' .. '\u0dc6'
    | '\u0dca'
    | '\u0dcf' .. '\u0dd4'
    | '\u0dd6'
    | '\u0dd8' .. '\u0ddf'
    | '\u0df2' .. '\u0df3'
    | '\u0e01' .. '\u0e3a'
    | '\u0e40' .. '\u0e4e'
    | '\u0e50' .. '\u0e59'
    | '\u0e81' .. '\u0e82'
    | '\u0e84'
    | '\u0e87' .. '\u0e88'
    | '\u0e8a'
    | '\u0e8d'
    | '\u0e94' .. '\u0e97'
    | '\u0e99' .. '\u0e9f'
    | '\u0ea1' .. '\u0ea3'
    | '\u0ea5'
    | '\u0ea7'
    | '\u0eaa' .. '\u0eab'
    | '\u0ead' .. '\u0eb9'
    | '\u0ebb' .. '\u0ebd'
    | '\u0ec0' .. '\u0ec4'
    | '\u0ec6'
    | '\u0ec8' .. '\u0ecd'
    | '\u0ed0' .. '\u0ed9'
    | '\u0edc' .. '\u0edd'
    | '\u0f00'
    | '\u0f18' .. '\u0f19'
    | '\u0f20' .. '\u0f29'
    | '\u0f35'
    | '\u0f37'
    | '\u0f39'
    | '\u0f3e' .. '\u0f47'
    | '\u0f49' .. '\u0f6a'
    | '\u0f71' .. '\u0f84'
    | '\u0f86' .. '\u0f8b'
    | '\u0f90' .. '\u0f97'
    | '\u0f99' .. '\u0fbc'
    | '\u0fc6'
    | '\u1000' .. '\u1021'
    | '\u1023' .. '\u1027'
    | '\u1029' .. '\u102a'
    | '\u102c' .. '\u1032'
    | '\u1036' .. '\u1039'
    | '\u1040' .. '\u1049'
    | '\u1050' .. '\u1059'
    | '\u10a0' .. '\u10c5'
    | '\u10d0' .. '\u10f8'
    | '\u1100' .. '\u1159'
    | '\u115f' .. '\u11a2'
    | '\u11a8' .. '\u11f9'
    | '\u1200' .. '\u1206'
    | '\u1208' .. '\u1246'
    | '\u1248'
    | '\u124a' .. '\u124d'
    | '\u1250' .. '\u1256'
    | '\u1258'
    | '\u125a' .. '\u125d'
    | '\u1260' .. '\u1286'
    | '\u1288'
    | '\u128a' .. '\u128d'
    | '\u1290' .. '\u12ae'
    | '\u12b0'
    | '\u12b2' .. '\u12b5'
    | '\u12b8' .. '\u12be'
    | '\u12c0'
    | '\u12c2' .. '\u12c5'
    | '\u12c8' .. '\u12ce'
    | '\u12d0' .. '\u12d6'
    | '\u12d8' .. '\u12ee'
    | '\u12f0' .. '\u130e'
    | '\u1310'
    | '\u1312' .. '\u1315'
    | '\u1318' .. '\u131e'
    | '\u1320' .. '\u1346'
    | '\u1348' .. '\u135a'
    | '\u1369' .. '\u1371'
    | '\u13a0' .. '\u13f4'
    | '\u1401' .. '\u166c'
    | '\u166f' .. '\u1676'
    | '\u1681' .. '\u169a'
    | '\u16a0' .. '\u16ea'
    | '\u16ee' .. '\u16f0'
    | '\u1700' .. '\u170c'
    | '\u170e' .. '\u1714'
    | '\u1720' .. '\u1734'
    | '\u1740' .. '\u1753'
    | '\u1760' .. '\u176c'
    | '\u176e' .. '\u1770'
    | '\u1772' .. '\u1773'
    | '\u1780' .. '\u17b3'
    | '\u17b6' .. '\u17d3'
    | '\u17d7'
    | '\u17dc' .. '\u17dd'
    | '\u17e0' .. '\u17e9'
    | '\u180b' .. '\u180d'
    | '\u1810' .. '\u1819'
    | '\u1820' .. '\u1877'
    | '\u1880' .. '\u18a9'
    | '\u1900' .. '\u191c'
    | '\u1920' .. '\u192b'
    | '\u1930' .. '\u193b'
    | '\u1946' .. '\u196d'
    | '\u1970' .. '\u1974'
    | '\u1d00' .. '\u1d6b'
    | '\u1e00' .. '\u1e9b'
    | '\u1ea0' .. '\u1ef9'
    | '\u1f00' .. '\u1f15'
    | '\u1f18' .. '\u1f1d'
    | '\u1f20' .. '\u1f45'
    | '\u1f48' .. '\u1f4d'
    | '\u1f50' .. '\u1f57'
    | '\u1f59'
    | '\u1f5b'
    | '\u1f5d'
    | '\u1f5f' .. '\u1f7d'
    | '\u1f80' .. '\u1fb4'
    | '\u1fb6' .. '\u1fbc'
    | '\u1fbe'
    | '\u1fc2' .. '\u1fc4'
    | '\u1fc6' .. '\u1fcc'
    | '\u1fd0' .. '\u1fd3'
    | '\u1fd6' .. '\u1fdb'
    | '\u1fe0' .. '\u1fec'
    | '\u1ff2' .. '\u1ff4'
    | '\u1ff6' .. '\u1ffc'
    | '\u203f' .. '\u2040'
    | '\u2054'
    | '\u2071'
    | '\u207f'
    | '\u20d0' .. '\u20dc'
    | '\u20e1'
    | '\u20e5' .. '\u20ea'
    | '\u2102'
    | '\u2107'
    | '\u210a' .. '\u2113'
    | '\u2115'
    | '\u2118' .. '\u211d'
    | '\u2124'
    | '\u2126'
    | '\u2128'
    | '\u212a' .. '\u2131'
    | '\u2133' .. '\u2139'
    | '\u213d' .. '\u213f'
    | '\u2145' .. '\u2149'
    | '\u2160' .. '\u2183'
    | '\u3005' .. '\u3007'
    | '\u3021' .. '\u302f'
    | '\u3031' .. '\u3035'
    | '\u3038' .. '\u303c'
    | '\u3041' .. '\u3096'
    | '\u3099' .. '\u309a'
    | '\u309d' .. '\u309f'
    | '\u30a1' .. '\u30ff'
    | '\u3105' .. '\u312c'
    | '\u3131' .. '\u318e'
    | '\u31a0' .. '\u31b7'
    | '\u31f0' .. '\u31ff'
    | '\u3400' .. '\u4db5'
    | '\u4e00' .. '\u9fa5'
    | '\ua000' .. '\ua48c'
    | '\uac00' .. '\ud7a3'
    | '\uf900' .. '\ufa2d'
    | '\ufa30' .. '\ufa6a'
    | '\ufb00' .. '\ufb06'
    | '\ufb13' .. '\ufb17'
    | '\ufb1d' .. '\ufb28'
    | '\ufb2a' .. '\ufb36'
    | '\ufb38' .. '\ufb3c'
    | '\ufb3e'
    | '\ufb40' .. '\ufb41'
    | '\ufb43' .. '\ufb44'
    | '\ufb46' .. '\ufbb1'
    | '\ufbd3' .. '\ufc5d'
    | '\ufc64' .. '\ufd3d'
    | '\ufd50' .. '\ufd8f'
    | '\ufd92' .. '\ufdc7'
    | '\ufdf0' .. '\ufdf9'
    | '\ufe00' .. '\ufe0f'
    | '\ufe20' .. '\ufe23'
    | '\ufe33' .. '\ufe34'
    | '\ufe4d' .. '\ufe4f'
    | '\ufe71'
    | '\ufe73'
    | '\ufe77'
    | '\ufe79'
    | '\ufe7b'
    | '\ufe7d'
    | '\ufe7f' .. '\ufefc'
    | '\uff10' .. '\uff19'
    | '\uff21' .. '\uff3a'
    | '\uff3f'
    | '\uff41' .. '\uff5a'
    | '\uff65' .. '\uffbe'
    | '\uffc2' .. '\uffc7'
    | '\uffca' .. '\uffcf'
    | '\uffd2' .. '\uffd7'
    | '\uffda' .. '\uffdc'
    | '\ud800' '\udc00' .. '\udc0a'
    | '\ud800' '\udc0d' .. '\udc25'
    | '\ud800' '\udc28' .. '\udc39'
    | '\ud800' '\udc3c' .. '\udc3c'
    | '\ud800' '\udc3f' .. '\udc4c'
    | '\ud800' '\udc50' .. '\udc5c'
    | '\ud800' '\udc80' .. '\udcf9'
    | '\ud800' '\udf00' .. '\udf1d'
    | '\ud800' '\udf30' .. '\udf49'
    | '\ud800' '\udf80' .. '\udf9c'
    | '\ud801' '\ue000' .. '\ue09c'
    | '\ud801' '\ue0a0' .. '\ue0a8'
    | '\ud802' '\ue400' .. '\ue404'
    | '\ud802' '\u0808'
    | '\ud802' '\ue40a' .. '\ue434'
    | '\ud802' '\ue437' .. '\ue437'
    | '\ud802' '\u083c'
    | '\ud802' '\u083f'
    | '\ud834' '\uad65' .. '\uad68'
    | '\ud834' '\uad6d' .. '\uad71'
    | '\ud834' '\uad7b' .. '\uad81'
    | '\ud834' '\uad85' .. '\uad8a'
    | '\ud834' '\uadaa' .. '\uadac'
    | '\ud835' '\ub000' .. '\ub053'
    | '\ud835' '\ub056' .. '\ub09b'
    | '\ud835' '\ub09e' .. '\ub09e'
    | '\ud835' '\ud4a2'
    | '\ud835' '\ub0a5' .. '\ub0a5'
    | '\ud835' '\ub0a9' .. '\ub0ab'
    | '\ud835' '\ub0ae' .. '\ub0b8'
    | '\ud835' '\ud4bb'
    | '\ud835' '\ub0bd' .. '\ub0c2'
    | '\ud835' '\ub0c5' .. '\ub104'
    | '\ud835' '\ub107' .. '\ub109'
    | '\ud835' '\ub10d' .. '\ub113'
    | '\ud835' '\ub116' .. '\ub11b'
    | '\ud835' '\ub11e' .. '\ub138'
    | '\ud835' '\ub13b' .. '\ub13d'
    | '\ud835' '\ub140' .. '\ub143'
    | '\ud835' '\ud546'
    | '\ud835' '\ub14a' .. '\ub14f'
    | '\ud835' '\ub152' .. '\ub2a2'
    | '\ud835' '\ub2a8' .. '\ub2bf'
    | '\ud835' '\ub2c2' .. '\ub2d9'
    | '\ud835' '\ub2dc' .. '\ub2f9'
    | '\ud835' '\ub2fc' .. '\ub313'
    | '\ud835' '\ub316' .. '\ub333'
    | '\ud835' '\ub336' .. '\ub34d'
    | '\ud835' '\ub350' .. '\ub36d'
    | '\ud835' '\ub370' .. '\ub387'
    | '\ud835' '\ub38a' .. '\ub3a7'
    | '\ud835' '\ub3aa' .. '\ub3c1'
    | '\ud835' '\ub3c4' .. '\ub3c8'
    | '\ud835' '\ub3ce' .. '\ub3fe'
    | '\ud840' '\udc00' .. '\udffe'
    | '\ud841' '\ue000' .. '\ue3fe'
    | '\ud842' '\ue400' .. '\ue7fe'
    | '\ud843' '\ue800' .. '\uebfe'
    | '\ud844' '\uec00' .. '\ueffe'
    | '\ud845' '\uf000' .. '\uf3fe'
    | '\ud846' '\uf400' .. '\uf7fe'
    | '\ud847' '\uf800' .. '\ufbfe'
    | '\ud848' '\ufc00' .. '\ufffe'
    | '\ud849' '\u0000' .. '\u03fe'
    | '\ud84a' '\u0400' .. '\u07fe'
    | '\ud84b' '\u0800' .. '\u0bfe'
    | '\ud84c' '\u0c00' .. '\u0ffe'
    | '\ud84d' '\u1000' .. '\u13fe'
    | '\ud84e' '\u1400' .. '\u17fe'
    | '\ud84f' '\u1800' .. '\u1bfe'
    | '\ud850' '\u1c00' .. '\u1ffe'
    | '\ud851' '\u2000' .. '\u23fe'
    | '\ud852' '\u2400' .. '\u27fe'
    | '\ud853' '\u2800' .. '\u2bfe'
    | '\ud854' '\u2c00' .. '\u2ffe'
    | '\ud855' '\u3000' .. '\u33fe'
    | '\ud856' '\u3400' .. '\u37fe'
    | '\ud857' '\u3800' .. '\u3bfe'
    | '\ud858' '\u3c00' .. '\u3ffe'
    | '\ud859' '\u4000' .. '\u43fe'
    | '\ud85a' '\u4400' .. '\u47fe'
    | '\ud85b' '\u4800' .. '\u4bfe'
    | '\ud85c' '\u4c00' .. '\u4ffe'
    | '\ud85d' '\u5000' .. '\u53fe'
    | '\ud85e' '\u5400' .. '\u57fe'
    | '\ud85f' '\u5800' .. '\u5bfe'
    | '\ud860' '\u5c00' .. '\u5ffe'
    | '\ud861' '\u6000' .. '\u63fe'
    | '\ud862' '\u6400' .. '\u67fe'
    | '\ud863' '\u6800' .. '\u6bfe'
    | '\ud864' '\u6c00' .. '\u6ffe'
    | '\ud865' '\u7000' .. '\u73fe'
    | '\ud866' '\u7400' .. '\u77fe'
    | '\ud867' '\u7800' .. '\u7bfe'
    | '\ud868' '\u7c00' .. '\u7ffe'
    | '\ud869' '\u8000' .. '\u82d5'
    | '\ud87e' '\ud400' .. '\ud61c'
    | '\udb40' '\udd00' .. '\uddee'
    ;

// === Modules and items

crate:
    mod_body EOF;

mod_body:
    inner_attr*  item*;

visibility:
    'pub' visibility_restriction?
    | 'crate'  //experimental, issue 46209
    ;

// Note that `pub(` does not necessarily signal the beginning of a visibility
// restriction! For example:
//
//     struct T(i32, i32, pub(i32));
//
// Here the `(` is part of the type `(i32)`.
visibility_restriction:
    '(' 'crate' ')'
    | '(' 'super' ')'
    | '(' 'in' simple_path ')';

item:
    attr* visibility? pub_item
    | attr* impl_block
    | attr* extern_mod
    | attr* macro_iterm
    | attr* '\''; // experimental ignore-tidy-cr
//TODO: attr* need to be moved to somewhere else here


pub_item
    : extern_crate     // `pub extern crate` is deprecated but still allowed
    | use_decl
    | mod_decl_short
    | mod_decl
    | static_decl
    | const_decl
    | associated_const_decl //experimental
    | associated_static_decl //experimental
    | fn_decl
    | type_decl
    | struct_decl
    | enum_decl
    | union_decl
    | trait_decl
    | trait_alias
    | macro_decl
    ;



// --- extern crate

extern_crate:
    'extern' 'crate' (ident|'self') rename? ';'; //experimental: extern-crate-self-pass


// --- use declarations

use_decl:
    'use' use_path ';';

use_path:
    '::'? '{' use_item_list? '}'
    | '::'? (any_ident|'*') ('::' any_ident)* use_suffix?;

use_suffix:
    '::' '*'
    | '::' '{' use_item_list? '}'
    | rename;

use_item:
    (any_ident | use_path | '*') rename?;

use_item_list:
    use_item (',' use_item)* ','?;

rename:
    'as' (ident | '_');


// --- Modules

mod_decl_short:
    'mod' ident ';';

mod_decl:
    'mod' ident '{' mod_body '}';


// --- Foreign modules

extern_mod:
    extern_abi '{' inner_attr* foreign_item* '}';

foreign_item:
    attr* visibility? foreign_item_tail
    | attr* macro_invocation_semi;

foreign_item_tail:
    'static' 'mut'? ident ':' type ('=' expr)? ';' // experimental: added ('=' expr)? . Syntactically, a foreign static may have a body.
    | 'type' ident type_parameters? colon_bound? where_clause? (':' type)? ('=' type)?';'
    | foreign_fn_decl;


// --- static and const declarations

static_decl:
    'static' 'mut'? ident ':' ty_sum '=' expr ';';

associated_static_decl:
    'static' 'mut'? ident ':' ty_sum';';

const_decl:
    'default'? 'const' (ident|'_') ':' ty_sum '=' expr ';';

associated_const_decl:
    'const' ident (':' ty_sum)? ';'; //experimental:  const ident syntactic but not semantically

// --- Functions

fn_decl:
    fn_head '(' param_list? ')' fn_rtype? where_clause? ( block_with_inner_attrs | ';'); //experimental for supporting `fn` forms having or lacking a body are syntactically valid.

method_decl:
    fn_head '(' method_param_list? ')' fn_rtype? where_clause? ( block_with_inner_attrs | ';');//experimental for supporting `fn` forms having or lacking a body are syntactically valid.

trait_method_decl:
    fn_head '(' trait_method_param_list? ')' rtype? where_clause? (block_with_inner_attrs | ';');

foreign_fn_decl:
    fn_head '(' variadic_param_list? ')' rtype? where_clause? ( block_with_inner_attrs | ';');  //experimental for supporting `fn` forms having or lacking a body are syntactically valid.

//macro declaration here is not documented,
macro_decl:
     macro_head ( '(' tt* ')' )? fn_rtype? where_clause? tt; // tt* should be replaced onced offical grammar is released

macro_head:
    'macro' ident type_parameter?;
// Parts of a `fn` definition up to the type parameters.
//
// `const` and `extern` are incompatible on a `fn`, but this grammar
// does not rule it out, holding that in a hypothetical Rust language
// specification, it would be clearer to specify this as a semantic
// rule, not a syntactic one. That is, not every rule that can be
// enforced gramatically should be.
fn_head:
    ('async' | 'const' | 'unsafe')*extern_abi? 'fn' ident type_parameters?; //experimental Ensures that all `fn` forms can have all the function qualifiers syntactically.

param:
    '...'
    | attr* mut_or_const? ~(EOF)? pattern ':' (param_ty|'...')
    | attr*  '&'? lifetime? mut_or_const?  'self' (':' type)?; // experimental:`self` is syntactically accepted

param_ty:
    ty_sum
    | 'impl' bound;  // experimental: feature(universal_impl_trait)

param_list:
    param (',' param)* (',' attr* pattern mut_or_const ':' '...')? ','?;

variadic_param_list:
     param (','  param)* (',' attr* '...')? ','?; //experimental c_variadic

variadic_param_list_names_optional:
    trait_method_param (',' trait_method_param)* (',' attr* '...')? ','?;

self_param:
    'mut'? 'self' (':' ty_sum)?
    | '&' lifetime? 'mut'? 'self';

method_param_list:
    (param | self_param) (',' param)* ','?;

// Argument names are optional in traits. The ideal grammar here would be
// `(pat ':')? ty_sum`, but parsing this would be unreasonably complicated.
// Instead, the `pat` is restricted to a few short, simple cases.
trait_method_param:
    '...'
    | attr* ( ('(' (restricted_pat ',')* restricted_pat')' ) |  restricted_pat) ':' attr* ty_sum
    | attr* ty_sum;

restricted_pat:
    'ref'? ('&' | '&&' | 'mut')? ('_' | ident);

trait_method_param_list:
    attr* (trait_method_param | self_param) (',' trait_method_param)* ','?;

// `ty_sum` is permitted in parameter types (although as a matter of semantics
// an actual sum is always rejected later, as having no statically known size),
// but only `ty` in return types. This means that in the where-clause
// `where T: Fn() -> X + Clone`, we're saying that T implements both
// `Fn() -> X` and `Clone`, not that its return type is `X + Clone`.
rtype
    : '->' type
    ;

// Experimental `feature(conservative_impl_trait)`.
fn_rtype:
    '->' (type | 'impl' bound);


// --- type, struct, and enum declarations

type_decl:
    'type' ident type_parameters? where_clause? '=' ty_sum ';'
    | 'type' ident type_parameters? colon_bound? where_clause? (':' type)? ('=' type)?';'; //experimental:test_data/rust_programs/rust_testsuite/ui/parser/item-free-type-bounds-syntactic-pass.rs

struct_decl:
    'struct' ident type_parameters? struct_tail;

struct_tail:
    where_clause? ';'
    | '(' tuple_struct_field_list? ')' where_clause? ';'
    | where_clause? '{' field_decl_list? '}';

tuple_struct_field:
    attr* visibility? ty_sum;

tuple_struct_field_list:
    tuple_struct_field (',' tuple_struct_field)* ','?;

field_decl:
    attr* visibility? ident ':' ty_sum;

field_decl_list:
    field_decl (',' field_decl)* ','?;

enum_decl:
    'enum' ident type_parameters? where_clause? '{' enum_variant_list? '}';

enum_variant:
    attr* visibility? enum_variant_main ('=' lit)?;

enum_variant_list:
    enum_variant (',' enum_variant)* ','?;

enum_variant_main:
    ident '(' enum_tuple_field_list? ')'
    | ident '{' enum_field_decl_list? '}'
    | ident '=' expr
    | ident;

// enum variants that are tuple-struct-like can't have `pub` on individual fields.
enum_tuple_field:
    attr* ty_sum;

enum_tuple_field_list:
    enum_tuple_field (',' enum_tuple_field)* ','?;

// enum variants that are struct-like can't have `pub` on individual fields.
enum_field_decl:
    attr*
    visibility?
    ident ':' ty_sum;

enum_field_decl_list:
    enum_field_decl (',' enum_field_decl)* ','?;

union_decl:
    'union' ident type_parameters? where_clause? '{' field_decl_list '}';


// --- Traits

// The `auto trait` syntax is an experimental feature, `optin_builtin_traits`,
// also known as OIBIT.
trait_decl:
    'unsafe'? 'auto'? 'trait' ident type_parameters? colon_bound? where_clause? '{'inner_attr* trait_item* '}';

trait_alias
    : 'trait' ident type_parameters? '='
        (ty_sum where_clause? | where_clause)  ';'
    ;

trait_item:
    attr* 'default'? visibility? 'type' ident type_parameters? colon_bound? where_clause? ty_default? ';'
    | attr* 'default'? 'const' ident ':' ty_sum const_default? ';'  // experimental associated constants
    | attr* 'default'? visibility? trait_method_decl
    | attr* 'default'? visibility? macro_invocation_semi // experimental:accept visibilities on items in traits syntactically but not semantically.
    | 'default'? visibility? (const_decl|associated_const_decl); //experimental

ty_default:
    '=' ty_sum;

const_default:
    '=' expr;


// --- impl blocks

impl_block:
    //experimental: ?const parse only
    'default'? 'unsafe'? 'impl' type_parameters? '?'? 'const'? impl_what where_clause? '{' impl_item* '}';

impl_what:
    '!' ty_sum 'for' ty_sum
    | ty_sum 'for' ty_sum
    | ty_sum 'for' '..'
    | ident type_arguments
    | ty_sum
    ;

impl_item:
    (attr|inner_attr)* visibility? impl_item_tail;

impl_item_tail:
    'default'? method_decl
    | 'default'? 'type' ident type_parameters? where_clause? '=' ty_sum ';'
    | (const_decl | associated_const_decl)
     // experimental test_data/rust_programs/rust_testsuite/ui/parser/impl-item-type-no-body-pass.rs
     // and test_data/rust_programs/rust_testsuite/ui/parser/self-param-syntactic-pass.rs
    | 'type' ident type_parameters? colon_bound? where_clause? (':' type)? ('=' tt*)?';'
    | macro_invocation_semi;


// === Attributes and token trees

attr:
    '#' '[' tt* ']';

inner_attr:
    '#' '!' '[' tt* ']';

tt:
    ~('(' | ')' | '{' | '}' | '[' | ']')
    | tt_delimited;

tt_delimited:
    tt_parens
    | tt_brackets
    | tt_block;

tt_parens:
    '(' tt* ')';

tt_brackets:
    '[' tt* ']';

tt_block:
    '{' tt* '}';

//nothing to do with macro now. Need to be refined in future
macro_tail:
    '!' tt_delimited;


// === Paths
// (forward references: ty_sum, ty_args)

// This is very slightly different from the syntax read by rustc:
// whitespace is permitted after `self` and `super` in paths.
//
// In rustc, `self::x` is an acceptable path, but `self :: x` is not,
// because `self` is a strict keyword except when followed immediately
// by the exact characters `::`. Same goes for `super`. Pretty weird.
//
// So instead, this grammar accepts that `self` is a keyword, and
// permits it specially at the very front of a path. Whitespace is
// ignored. `super` is OK anywhere except at the end.
//
// Separately and more tentatively: in rustc, qualified paths are
// permitted in peculiarly constrained contexts. In this grammar,
// qualified paths are just part of the syntax of paths (for now -
// this is not clearly an OK change).

path:
    path_segment_no_super
    | path_parent? '::' path_segment_no_super;

path_parent:
    'self'
    | '<' ty_sum as_trait? '>'
    | path_segment
    | '::' path_segment
    | path_parent '::' path_segment;

as_trait:
    'as' ty_sum;

path_segment:
    path_segment_no_super
    | 'super';

path_segment_no_super:
    simple_path_segment ('::' type_arguments)?;

simple_path:
    '::'? simple_path_segment ( '::' simple_path_segment)*;

simple_path_segment:
    ident
    | 'super'
    | 'Self'
    | 'crate'
    | '$crate';


// === Type paths
// (forward references: rtype, ty_sum, ty_args)

for_lifetimes:
    'for' '<' lifetime_def_list? '>';

lifetime_def_list:
    lifetime_def (',' lifetime_def)* ','?;

lifetime_def:
    lifetime (':' lifetime_bound)?;

lifetime_bound:
    lifetime
    | lifetime_bound '+' lifetime;

type_path_main:
    ty_path_tail
    | ty_path_parent? '::' ty_path_tail;

ty_path_tail:
    (ident | 'Self') '(' ty_sum_list? ')' rtype?
    | ty_path_segment_no_super;

ty_path_parent:
    'self'
    | '<' ty_sum as_trait? '>'
    | type_path_segment
    | '::' type_path_segment
    | ty_path_parent '::' type_path_segment;

type_path_segment:
    ty_path_segment_no_super
    | 'super';

ty_path_segment_no_super:
    '(' (ident | 'Self')? ')' type_arguments?
    | (ident | 'Self'| '&raw') type_arguments?;


// === Type bounds

where_clause:
    'where' where_bound_list;

where_bound_list:
    where_bound (',' where_bound)* ','?;

where_bound:
    lifetime ':' lifetime_bound
    | for_lifetimes? type empty_ok_colon_bound ?;

empty_ok_colon_bound:
    ':' bound?;

colon_bound:
    ':' bound;

bound:
    prim_bound
    | bound '+' prim_bound
    | bound '<' (lifetime_param ',')* type_parameter_list '>'; //experimental for associated_type_bounds

prim_bound:
    | '?'? for_lifetimes? ('dyn' | 'impl')? type_path_main
    | lifetime;


// === Types and type parameters

type
    : type_no_bounds
    | '&&' lifetime? 'mut'? type          // meaning `& & ty`
    | impl_trait_type
    | trait_object_type
    | '{' expr '}'
    ;

type_no_bounds
    : impl_trait_type_one_bound
    | trait_object_type_one_bound
    | '(' ty_sum ')'                    // grouping (parens are ignored)
    | tuple_type
    | never_type
    | raw_pointer_type
    | reference_type
    | array_or_slice_type
    | inferred_type
    | bare_function_type
    | macro_invocation
    ;

inferred_type
    : '_'
    ;

array_or_slice_type
    : '[' ty_sum (';' expr)? ']'
    ;

reference_type
    : '&' lifetime? 'mut'? type
    ;

raw_pointer_type
    : '*' mut_or_const type
    ;

never_type
    : '!'
    ;

tuple_type
    : '(' ')'
    | '(' ty_sum ',' ty_sum_list? ')'
    ;

impl_trait_type
    : 'impl' type_param_bounds
    ;

impl_trait_type_one_bound
    : 'impl' trait_bound
    ;

trait_object_type_one_bound
    : 'dyn'? trait_bound
    ;

type_param_bounds
    : type_param_bound ('+' type_param_bound)* '+'?
    ;

type_param_bound
    : lifetime
    | trait_bound
    ;

trait_object_type
    : 'dyn'? type_param_bounds?
    ;

trait_bound
    : '?'? for_lifetimes? type_path_main
    | '(' '?'? for_lifetimes? type_path_main ')'
    ;

bare_function_type
    : for_lifetimes? 'unsafe'? extern_abi? 'fn' '(' variadic_param_list_names_optional? ')' rtype?
    ;

mut_or_const:
    'mut'
    | 'const';

extern_abi:
    'extern' StringLit?;

type_arguments:
    '<' lifetime (',' (lifetime | type_argument))* ','? '>'
    | '<' (lifetime ',')* type_argument (',' type_argument)* ','? '>';

type_argument:
    ident '=' ty_sum
    | ty_sum
    | BareIntLit
    | 'true'
    | 'false'
    ;

// TODO(cnsun): get rid of this.
ty_sum:
   'dyn'? type ('+' bound)?;

ty_sum_list:
    ty_sum (',' ty_sum)* ','?;

type_parameters:
    '<' lifetime_param_list '>'
    | '<' (lifetime_param ',')* type_parameter_list? '>';

lifetime_param:
    attr* 'const'? lifetime (':' lifetime_bound)?;

lifetime_param_list:
    lifetime_param (',' lifetime_param)* ','?;

type_parameter:
    attr* 'const'? ident colon_bound? ty_default?
    | ty_sum;

type_parameter_list:
    type_parameter (',' type_parameter)* ','?;


// === Patterns

pattern:
    pattern_without_mut
    | 'mut' ident ('@' pattern)?;

pat_ident:
    ('_' | 'ref' ident);

// A `pattern_without_mut` is a pattern that does not start with `mut`.
// It is distinct from `pattern` to rule out ambiguity in parsing the
// pattern `&mut x`, which must parse like `&mut (x)`, not `&(mut x)`.
pattern_without_mut:
    '_' // wildcard pattern
    | '..' //experimental
    |  pattern_without_mut '|' pattern_without_mut //experimental
    | '|' pattern_without_mut '|'? //experimental
	| ident ('@' match_pattern)?
    | ident ('@' '(' match_pattern ')' )
    | pat_lit //litreal pattern
    | pat_range_end '...' pat_range_end // range pattern
    | pat_range_end '..' pat_range_end  // experimental `feature(exclusive_range_pattern)`
    | pat_range_end '..=' pat_range_end
    | path macro_tail
    | (pat_ident ',')* pat_ident ('@' pattern)?
    | 'ref'? 'mut'? ident ('@' pattern)? //IDpattern
    | path '(' pat_list_with_dots? ')'
    | path '{' pat_fields? '}'
    | path  // BUG: ambiguity with bare ident case (above)
    | '(' pat_list_with_dots? ')'
    | '[' pattern ( ',' pattern )* ','? ']' // slice pattern
    | '['']'
    | '&' pattern_without_mut
    | '&' 'mut' pattern
    | '&&' pattern_without_mut   // `&& pat` means the same as `& & pat`
    | '&&' 'mut' pattern
    | 'box' pattern
    | '$' pattern;

pat_range_end:
    path
    | pat_lit;

pat_lit:
    '-'? lit;

pat_list:
    pattern (',' pattern)* ','?;

pat_list_with_dots:
    pat_list_dots_tail
    | match_pattern (',' pattern)* (',' pat_list_dots_tail?)?;

pat_list_dots_tail:
    '..' (',' pat_list)?;

// rustc does not accept `[1, 2, tail..,]` as a pattern, because of the
// trailing comma, but I don't see how this is justifiable.  The rest of the
// language is *extremely* consistent in this regard, so I allow the trailing
// comma here.
//
// This grammar does not enforce the rule that a given slice pattern must have
// at most one `..`.


pat_fields_left:
    (ident | BareIntLit | FullIntLit);

pat_fields:
    '..'
    | pat_fields_left ':' pat_fields_left ((',' pat_fields_left ':' pat_fields_left)|(',' '..'))*
    | pat_field (',' pat_field)* (',' '..' | ','?);

pat_field:
    attr* 'box'? 'ref'? 'mut'? ident
    | attr* ident ':' pattern;


// === Expressions

expr:
   '&raw'? mut_or_const? assign_expr;

expr_no_struct:
    '&raw'? mut_or_const? assign_expr_no_struct;

expr_list:
    expr (',' expr)* ','?;


// --- Blocks

// OK, this is super tricky. There is an ambiguity in the grammar for blocks,
// `{ stmt* expr? }`, since there are strings that match both `{ stmt expr }`
// and `{ expr }`.
//
// The rule in Rust is that the `{ stmt expr }` parse is preferred: the body
// of the block `{ loop { break } - 1 }` is a `loop` statement followed by
// the expression `-1`, not a single subtraction-expression.
//
// Agreeably, the rule to resolve such ambiguities in ANTLR4, as in JS regexps,
// is the same. Earlier alternatives that match are preferred over later
// alternatives that match longer sequences of source tokens.
block:
    '{' stmt* expr? '}';

// Shared by blocky_expr and fn_body; in the latter case, any inner attributes
// apply to the whole fn.
block_with_inner_attrs:
    '{' inner_attr* stmt* expr? '}';

stmt
    : ';'
    | item  // Statement macros are included here.
    | attr* 'let' match_pattern (':' type)? ('=' expr)? ';'
    | attr* blocky_expr
    | expr ';'
    | macro_invocation_semi
    ;

// Inner attributes in `match`, `while`, `for`, `loop`, and `unsafe` blocks are
// experimental, `feature(stmt_expr_attributes)`.
blocky_expr
    : block_with_inner_attrs
    | if_cond_or_pat block ('else'  if_cond_or_pat block)* ('else' block)?
    | 'match' expr_no_struct '{' inner_attr? match_arms? '}'
    | loop_label? while_cond_or_pat block_with_inner_attrs
    | loop_label? 'for' pattern 'in' expr_no_struct block_with_inner_attrs
    | loop_label? 'loop' block_with_inner_attrs
    | loop_label? block_with_inner_attrs
    | 'unsafe' block_with_inner_attrs
    | 'try' block_with_inner_attrs
    | 'async' block_with_inner_attrs
    ;

if_cond_or_pat:
    'if' expr_no_struct
    | 'if' 'let' pattern '=' expr;

while_cond_or_pat:
    'while' expr_no_struct
    | 'while' 'let' pattern '=' expr;

loop_label:
    lifetime ':';

match_arms:
    match_arm_intro blocky_expr ','? match_arms?
    | match_arm_intro expr (',' match_arms?)?;

match_arm_intro:
    attr* match_pattern match_if_clause? '=>';

match_pattern:
    '|'? pattern ('|' pattern)*
    ;

match_if_clause:
    'if' expr;


// --- Primary expressions

// Attributes on expressions are experimental.
// Enable with `feature(stmt_expr_attributes)`.
expr_attrs:
    attr attr*;

// Inner attributes in array and struct expressions are experimental.
// Enable with `feature(stmt_expr_attributes)`.
expr_inner_attrs:
    inner_attr inner_attr*;

prim_expr:
    prim_expr_no_struct
    | path '{' expr_inner_attrs? fields? '}';

prim_expr_no_struct
    : lit
    | 'self'
    | path macro_tail?
    // The next 3 productions match exactly `'(' expr_list ')'`,
    // but (e) and (e,) are distinct expressions, so match them separately
    | '(' expr_inner_attrs? ')'
    | '(' expr_inner_attrs? expr ')'
    | '(' expr_inner_attrs? expr ',' expr_list? ')'
    | '[' expr_inner_attrs? expr_list? ']'
    | '[' expr_inner_attrs? expr ';' expr ']'
    | 'static'? 'move'? closure_params closure_tail
    | 'async' 'move' (blocky_expr | closure_params closure_tail)
    | blocky_expr
    | 'break' lifetime_or_expr? lit? item? expr? //experimental: label/loop break value
    | 'continue' lifetime?
    | 'return' expr? // this is IMO a rustc bug, should be expr_no_struct
    | 'yield' expr?
    ;

lit:
    'true'
    | 'false'
    | BareIntLit
    | FullIntLit
    | ByteLit
    | ByteStringLit
    | FloatLit
    | CharLit
    | StringLit;

closure_params
    : '|' '|'
    | '||'
    | '|_|'
    | '|' closure_param_list? '|';

closure_param:
    attr* pattern (':' type)?;

closure_param_list:
    closure_param (',' closure_param)* ','?;

closure_tail
    : rtype? block
    | expr;

lifetime_or_expr:
    lifetime
    | expr_no_struct;

fields:
    struct_update_base
    | field (',' field)* (',' struct_update_base | ','?);

struct_update_base:
    '..' expr;  // this is IMO a bug in the grammar. should be or_expr or something.

field:
    ident  // struct field shorthand (field and local variable have the same name)
    | expr_attrs* field_name ':' expr;

field_name:
    ident
    | BareIntLit;  // Allowed for creating tuple struct values.


// --- Operators

post_expr:
    prim_expr
    | post_expr post_expr_tail;

post_expr_tail:
    '?'
    | '[' expr ']'
    | '.' ident (('::' type_arguments)? '(' expr_list? ')')?
    | '.' BareIntLit
    | '(' expr_list? ')';

pre_expr:
    post_expr
    | expr_attrs pre_expr
    | '-' pre_expr
    | '!' pre_expr
    | '&raw'
    | '&' 'mut'? pre_expr
    | '&&' 'mut'? pre_expr   // meaning `& & expr`
    | '*' pre_expr
    | 'box' pre_expr
    | 'in' expr_no_struct block;  // placement new - possibly not the final syntax

cast_expr:
    pre_expr
    | cast_expr 'as' ty_sum
    | cast_expr ':' ty_sum;  // experimental type ascription

mul_expr:
    cast_expr
    | mul_expr '*' cast_expr
    | mul_expr '/' cast_expr
    | mul_expr '%' cast_expr;

add_expr:
    mul_expr
    | add_expr '+' mul_expr
    | add_expr '-' mul_expr;

shift_expr:
    add_expr
    | shift_expr '<' '<' add_expr
    | shift_expr '>' '>' add_expr;

bit_and_expr:
    shift_expr
    | bit_and_expr '&' shift_expr;

bit_xor_expr:
    bit_and_expr
    | bit_xor_expr '^' bit_and_expr;

bit_or_expr:
    bit_xor_expr
    | bit_or_expr '|' bit_xor_expr;

cmp_expr:
    bit_or_expr
    | bit_or_expr ('==' | '!=' | '<' | '<='  | '>' | '>=') bit_or_expr;

and_expr:
    cmp_expr
    | and_expr '&&' cmp_expr;

or_expr:
    and_expr
    | or_expr '||' and_expr;

range_expr:
    or_expr
    | or_expr '..' or_expr?
    | or_expr '..=' or_expr?
    | '..' or_expr?
    | '..=' or_expr?;

assign_expr:
    range_expr
    | range_expr ('=' | '*=' | '/=' | '%=' | '+=' | '-='
                      | '<<=' | '>>=' | '&=' | '^=' | '|=' ) assign_expr;


// --- Copy of the operator expression syntax but without structs

post_expr_no_struct:
    prim_expr_no_struct
    | post_expr_no_struct post_expr_tail;

pre_expr_no_struct:
    post_expr_no_struct
    | expr_attrs pre_expr_no_struct
    | '-' pre_expr_no_struct
    | '!' pre_expr_no_struct
    | '&' 'mut'? pre_expr_no_struct
    | '&&' 'mut'? pre_expr_no_struct   // meaning `& & expr`
    | '*' pre_expr_no_struct
    | 'box' pre_expr_no_struct;

cast_expr_no_struct:
    pre_expr_no_struct
    | cast_expr_no_struct 'as' ty_sum
    | cast_expr_no_struct ':' ty_sum;  // experimental type ascription

mul_expr_no_struct:
    cast_expr_no_struct
    | mul_expr_no_struct '*' cast_expr_no_struct
    | mul_expr_no_struct '/' cast_expr_no_struct
    | mul_expr_no_struct '%' cast_expr_no_struct;

add_expr_no_struct:
    mul_expr_no_struct
    | add_expr_no_struct '+' mul_expr_no_struct
    | add_expr_no_struct '-' mul_expr_no_struct;

shift_expr_no_struct:
    add_expr_no_struct
    | shift_expr_no_struct '<' '<' add_expr_no_struct
    | shift_expr_no_struct '>' '>' add_expr_no_struct;

bit_and_expr_no_struct:
    shift_expr_no_struct
    | bit_and_expr_no_struct '&' shift_expr_no_struct;

bit_xor_expr_no_struct:
    bit_and_expr_no_struct
    | bit_xor_expr_no_struct '^' bit_and_expr_no_struct;

bit_or_expr_no_struct:
    bit_xor_expr_no_struct
    | bit_or_expr_no_struct '|' bit_xor_expr_no_struct;

cmp_expr_no_struct:
    bit_or_expr_no_struct
    | '&raw'? mut_or_const? bit_or_expr_no_struct ('==' | '!=' | '<' | '<=' | '>' | '>' '=') '&raw'? mut_or_const? bit_or_expr_no_struct;

and_expr_no_struct:
    cmp_expr_no_struct
    | and_expr_no_struct '&&' cmp_expr_no_struct;

or_expr_no_struct:
    and_expr_no_struct
    | or_expr_no_struct '||' and_expr_no_struct;

range_expr_no_struct:
    or_expr_no_struct
    | or_expr_no_struct '..' or_expr_no_struct?
    | or_expr_no_struct '..=' or_expr_no_struct?
    | '..' or_expr_no_struct?
    | '..=' or_expr_no_struct?;

assign_expr_no_struct:
    range_expr_no_struct
    | range_expr_no_struct ('=' | '*=' | '/=' | '%=' | '+=' | '-='
                                | '<<=' | '>' '>' '=' | '&=' | '^=' | '|=' |'>='|'<=') assign_expr_no_struct;


// === Tokens

// `auto`, `default`, and 'union' are identifiers, but in certain places
// they're specially recognized as keywords.
ident:
    Ident
    | 'auto'
    | 'default'
    | 'union'
    | 'try'
    | 'crate'
    | 'macro_rules'
    | RawIdentifier
    ;

any_ident:
    ident
    | 'crate'
    | 'Self'
    | 'self'
    | 'static'
    | 'super';


// TODO: tokens '<<' '>>' confilcts ty_args, type need to be refactored

//TOD0:classify this token

tokens_no_delimiters_cash:
    ~('(' | ')' | '{' | '}' | '[' | ']' | CashMoney);



tokens_no_delimiters_repetition_operators:
    ~('(' | ')' | '{' | '}' | '[' | ']' | '+'|'*'|'?');
//not complete all tokens need to be refactored

//token:
//    keyword_token
//    | ident
//    | lit
//    | lifetime
//    | punctuation
//    | delimiter;


//macro rules
macro_iterm:
    macro_rules_definition
    |macro_invocation_semi;


macro_rules_definition:
    'macro_rules' '!' (~EOF)? macro_rules_def; //experimental: relex syntax for allowing macro_rules declaration with invalid name or without name

macro_rules_def:
    '(' macro_rules?')' ';'
    | '[' macro_rules? ']' ';'
    | '{' macro_rules? '}' ;
 //experimental: relex syntax for allowing empty macro rules body

macro_rules:
    macro_rule ( ';' macro_rule)* ';'? ;

macro_rule:
    macro_matcher '=>' macro_transcriber;

macro_matcher:
    '(' macro_match* ')'
    |'[' macro_match* ']'
    |'{' macro_match* '}';

macro_match:
    tokens_no_delimiters_cash
    |macro_matcher
    |'$' ~(EOF) ':' macro_frag_spec
    |'$' '(' macro_match+ ')'  macro_rep_sep? macro_rep_op;


macro_frag_spec:
    ~EOF;
//TODO:
// should be
//    'block' | 'expr' | 'ident' | 'item' | 'lifetime' | 'literal'
//    | 'meta' | 'pat' | 'path' | 'stmt' | 'tt' | 'ty' | 'vis';
// but it will mismatch some IDs


macro_rep_sep:
    tokens_no_delimiters_repetition_operators;

macro_rep_op:
    '*' | '+' | '?';

macro_transcriber:
    delim_token_tree;

delim_token_tree:
    '(' tt* ')'
    | '[' tt* ']'
    | '{' tt* '}';


macro_invocation_semi:
    simple_path '!' '(' tt* ')' ';'
    | simple_path '!' '[' tt* ']' ';'
    | simple_path '!' '{' tt* '}' ;

macro_invocation:
    simple_path '!' delim_token_tree;

// `$` is recognized as a token, so it may be present in token trees,
// and `macro_rules!` makes use of it. But it is not mentioned anywhere
// else in this grammar.
CashMoney:
    '$';

RawIdentifier:
    'r#' IDENT
    ;

fragment IDENT:
    XID_Start XID_Continue*;

lifetime
    : Lifetime
    | '\'static'
    | '\'_'
    ;

Lifetime:
    [']IDENT;

Ident:
    IDENT;

fragment SIMPLE_ESCAPE:
    '\\' [0nrt'"\\];

fragment CHAR:
    ~['"\r\n\\\ud800-\udfff]          // a single BMP character other than a backslash, newline, or quote
    | [\ud800-\udbff][\udc00-\udfff]  // a single non-BMP character (hack for Java)
    | SIMPLE_ESCAPE
    | '\\x' [0-7] [0-9a-fA-F]
    | '\\u{' [0-9a-fA-F]+ '}';

CharLit:
    '\'' (CHAR | '"') '\'';

fragment OTHER_STRING_ELEMENT:
    '\''
    | '\\' '\r'? '\n' [ \t]*
    | '\r'
    | '\n';

fragment STRING_ELEMENT:
    CHAR
    | OTHER_STRING_ELEMENT;

fragment RAW_CHAR:
    ~[\ud800-\udfff]          // any BMP character
    | [\ud800-\udbff][\udc00-\udfff];  // any non-BMP character (hack for Java)

// Here we use a non-greedy match to implement the
// (non-regular) rules about raw string syntax.
fragment RAW_STRING_BODY:
    '"' RAW_CHAR*? '"'
    | '#' RAW_STRING_BODY '#';

StringLit:
    '"' STRING_ELEMENT* '"'
    | 'r' RAW_STRING_BODY;

fragment BYTE:
    ' '               // any ASCII character from 32 (space) to 126 (`~`),
    | '!'             // except 34 (double quote), 39 (single quote), and 92 (backslash)
    | [#-&]
    | [(-[]
    | ']'
    | '^'
    | [_-~]
    | SIMPLE_ESCAPE
    | '\\x' [0-9a-fA-F][0-9a-fA-F];

ByteLit:
    'b\'' (BYTE | '"') '\'';

fragment BYTE_STRING_ELEMENT:
    BYTE
    | OTHER_STRING_ELEMENT;

fragment RAW_BYTE_STRING_BODY:
    '"' [\t\r\n -~]*? '"'
    | '#' RAW_BYTE_STRING_BODY '#';

ByteStringLit:
    'b"' BYTE_STRING_ELEMENT* '"'
    | 'br' RAW_BYTE_STRING_BODY;

fragment DEC_DIGITS:
    [0-9][0-9_]*;

// BareIntLit and FullIntLit both match '123'; BareIntLit wins by virtue of
// appearing first in the file. (This comment is to point out the dependency on
// a less-than-obvious ANTLR rule.)
BareIntLit:
    DEC_DIGITS;

fragment INT_SUFFIX:
    [ui] ('8'|'16'|'32'|'64'|'128'|'size');

FullIntLit:
    DEC_DIGITS INT_SUFFIX?
    | '0x' '_'* [0-9a-fA-F] [0-9a-fA-F_]* INT_SUFFIX?
    | '0o' '_'* [0-7] [0-7_]* INT_SUFFIX?
    | '0b' '_'* [01] [01_]* INT_SUFFIX?;

fragment EXPONENT:
    [Ee] [+-]? 'd_'* [0-9] [0-9_]*;

fragment FLOAT_SUFFIX:
    'f32'
    | 'f64';

// Some lookahead is required here. ANTLR does not support this
// except by injecting some Java code into the middle of the pattern.
//
// A floating-point literal may end with a dot, but:
//
// *   `100..f()` is parsed as `100 .. f()`, not `100. .f()`,
//     contrary to the usual rule that lexers are greedy.
//
// *   Similarly, but less important, a letter or underscore after `.`
//     causes the dot to be interpreted as a separate token by itself,
//     so that `1.abs()` parses a method call. The type checker will
//     later reject it, though.
//
FloatLit
    :
    ( DEC_DIGITS '.' [0-9] [0-9_]* EXPONENT? FLOAT_SUFFIX?
    | DEC_DIGITS ('.' {
        /* dot followed by another dot is a range, not a float */
        _input.LA(1) != '.' &&
        /* dot followed by an identifier is an integer with a function call, not a float */
        _input.LA(1) != '_' &&
        !(_input.LA(1) >= 'a' && _input.LA(1) <= 'z') &&
        !(_input.LA(1) >= 'A' && _input.LA(1) <= 'Z')
      }?)
    | DEC_DIGITS EXPONENT FLOAT_SUFFIX?
    | DEC_DIGITS FLOAT_SUFFIX
    )
    { lastToken == null || !".".equals(lastToken.getText()) }? // This is for (1, (2, 3)).1.1
    ;

Whitespace:
    [ \t\r\n]+ -> skip;

LineComment:
    '//' ~[\r\n]* -> skip;

BlockComment:
    '/*' (~[*/] | '/'* BlockComment | '/'+ (~[*/]) | '*'+ ~[*/])* '*'+ '/' -> skip;

Shebang:
    '#!/' ~[\r\n]* -> skip;

// BUG: only ascii identifiers are permitted
// BUG: doc comments are ignored
// BUG: associated constants are not supported
// BUG: rename `lit` -> `literal`
// BUG: probably inner attributes are allowed in many more places
// BUG: refactor `use_path` syntax to be like `path`, remove `any_ident`
// BUG: `let [a, xs.., d] = out;` does not parse
// BUG: ambiguity between expression macros, stmt macros, item macros
