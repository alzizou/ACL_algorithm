  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 89;
      section.data(89)  = dumData; %prealloc
      
	  ;% rtP.B
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.BBT_inv
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 36;
	
	  ;% rtP.J
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 72;
	
	  ;% rtP.Ka
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 81;
	
	  ;% rtP.Kd
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 82;
	
	  ;% rtP.Kf
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 83;
	
	  ;% rtP.Kt
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 84;
	
	  ;% rtP.L
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 85;
	
	  ;% rtP.M
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 86;
	
	  ;% rtP.Q
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 87;
	
	  ;% rtP.R
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 123;
	
	  ;% rtP.RM_1
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 159;
	
	  ;% rtP.alpha_P
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 175;
	
	  ;% rtP.alpha_Slid
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 176;
	
	  ;% rtP.alpha_V
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 177;
	
	  ;% rtP.gamma_0
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 178;
	
	  ;% rtP.gamma_1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 214;
	
	  ;% rtP.ge
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 250;
	
	  ;% rtP.k1
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 251;
	
	  ;% rtP.k1o
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 252;
	
	  ;% rtP.k2
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 253;
	
	  ;% rtP.k2o
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 254;
	
	  ;% rtP.rho_0
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 255;
	
	  ;% rtP.rho_1
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 256;
	
	  ;% rtP.Gain2_Gain
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 257;
	
	  ;% rtP.Integrator_IC
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 258;
	
	  ;% rtP.TransportDelay_Delay
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 270;
	
	  ;% rtP.TransportDelay_InitOutput
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 271;
	
	  ;% rtP.TransportDelay1_Delay
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 272;
	
	  ;% rtP.TransportDelay1_InitOutput
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 273;
	
	  ;% rtP.TransportDelay2_Delay
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 274;
	
	  ;% rtP.TransportDelay2_InitOutput
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 275;
	
	  ;% rtP.Integrator3_IC
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 276;
	
	  ;% rtP.Integrator2_IC
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 282;
	
	  ;% rtP.Integrator1_IC
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 284;
	
	  ;% rtP.Integrator_IC_bzpo215sgo
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 286;
	
	  ;% rtP.Integrator1_IC_kniptj1kxt
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 287;
	
	  ;% rtP.Gain_Gain
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 288;
	
	  ;% rtP.Memory_InitialCondition
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 289;
	
	  ;% rtP.Integrator_IC_kjcjwivfdd
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 295;
	
	  ;% rtP.Integrator1_IC_bfgbvvrang
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 301;
	
	  ;% rtP.Integrator1_IC_etk5iarzoa
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 307;
	
	  ;% rtP.Integrator_IC_d53cezkjnk
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 343;
	
	  ;% rtP.Integrator2_IC_milw2qy4e1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 379;
	
	  ;% rtP.Integrator3_IC_mvcbk0lpqx
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 385;
	
	  ;% rtP.Memory_InitialCondition_ltjalipc0r
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 391;
	
	  ;% rtP.Integrator_IC_i2crhtqu0w
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 397;
	
	  ;% rtP.Integrator1_IC_og2211l4hi
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 403;
	
	  ;% rtP.Integrator1_IC_ea4j2itlpr
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 409;
	
	  ;% rtP.Integrator_IC_lijhdzhcao
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 445;
	
	  ;% rtP.Integrator2_IC_eshmddcula
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 481;
	
	  ;% rtP.Memory_InitialCondition_cltcggngaa
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 487;
	
	  ;% rtP.Gain_Gain_pqv5poqtm5
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 499;
	
	  ;% rtP.SineWave_Amp
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 500;
	
	  ;% rtP.SineWave_Bias
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 501;
	
	  ;% rtP.SineWave_Freq
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 502;
	
	  ;% rtP.SineWave_Phase
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 503;
	
	  ;% rtP.SineWave1_Amp
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 504;
	
	  ;% rtP.SineWave1_Bias
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 505;
	
	  ;% rtP.SineWave1_Freq
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 506;
	
	  ;% rtP.SineWave1_Phase
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 507;
	
	  ;% rtP.Constant_Value
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 508;
	
	  ;% rtP.TransferFcn2_A
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 509;
	
	  ;% rtP.TransferFcn2_C
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 510;
	
	  ;% rtP.Constant1_Value
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 511;
	
	  ;% rtP.TransferFcn3_A
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 512;
	
	  ;% rtP.TransferFcn3_C
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 513;
	
	  ;% rtP.Constant2_Value
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 514;
	
	  ;% rtP.TransferFcn1_A
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 515;
	
	  ;% rtP.TransferFcn1_C
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 516;
	
	  ;% rtP.FromWs_Time0
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 517;
	
	  ;% rtP.FromWs_Data0
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 523;
	
	  ;% rtP.TransferFcn_A
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 529;
	
	  ;% rtP.TransferFcn_C
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 530;
	
	  ;% rtP.FromWorkspace_Time0
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 531;
	
	  ;% rtP.FromWorkspace_Data0
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 1132;
	
	  ;% rtP.Gain_Gain_bttrwertaz
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 1733;
	
	  ;% rtP.FromWorkspace1_Time0
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 1734;
	
	  ;% rtP.FromWorkspace1_Data0
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 2335;
	
	  ;% rtP.Gain1_Gain
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 2936;
	
	  ;% rtP.FromWorkspace3_Time0
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 2937;
	
	  ;% rtP.FromWorkspace3_Data0
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 3538;
	
	  ;% rtP.DesiredPosition4_Value
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 4139;
	
	  ;% rtP.Switch_Threshold
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 4140;
	
	  ;% rtP.Constant2_Value_p1uxhfeofi
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 4141;
	
	  ;% rtP.Constant1_Value_k0amvdt1or
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 4144;
	
	  ;% rtP.Integrator1_IC_cysw5lmkvd
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 4146;
	
	  ;% rtP.Gain_Gain_mauqb2akec
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 4147;
	
	  ;% rtP.Integrator_IC_mdtcnu4jbd
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 4148;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 17;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% rtB.f3qdvlncs2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.cvaerauj1g
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 12;
	
	  ;% rtB.luue0kfi2i
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% rtB.cp0haf23uy
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 14;
	
	  ;% rtB.out1onmc3n
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 15;
	
	  ;% rtB.iyrr00rsy5
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 18;
	
	  ;% rtB.dhldqomrw2
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 24;
	
	  ;% rtB.jgeak2pmpa
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 36;
	
	  ;% rtB.fkn5pxjywf
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 38;
	
	  ;% rtB.eja0y2gles
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 40;
	
	  ;% rtB.ncyc1gpaj2
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 46;
	
	  ;% rtB.mqwm4nfdap
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 52;
	
	  ;% rtB.pnzkimrl2h
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 58;
	
	  ;% rtB.fjffiex4ix
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 94;
	
	  ;% rtB.c05vhcs2pf
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 130;
	
	  ;% rtB.m2sfecaklo
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 136;
	
	  ;% rtB.oidskutggb
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 142;
	
	  ;% rtB.o2eyjfo1wi
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 148;
	
	  ;% rtB.m0blghypsp
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 154;
	
	  ;% rtB.es2yapuiac
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 160;
	
	  ;% rtB.ix2okivzvw
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 196;
	
	  ;% rtB.mghhh4y54x
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 232;
	
	  ;% rtB.hut5rsdm1t
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 238;
	
	  ;% rtB.db0sdie5cx
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 239;
	
	  ;% rtB.olp0aypydn
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 240;
	
	  ;% rtB.hdwtb14kjv
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 241;
	
	  ;% rtB.h0vfo44bet
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 242;
	
	  ;% rtB.apsqtgdw2k
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 243;
	
	  ;% rtB.niozx0x3bq
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 244;
	
	  ;% rtB.bzt0lwzvse
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 245;
	
	  ;% rtB.hrymkwe4oo
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 246;
	
	  ;% rtB.a2l3vjk5kk
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 249;
	
	  ;% rtB.bslv0j5s21
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 251;
	
	  ;% rtB.dlysorqgi3
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 253;
	
	  ;% rtB.ab5rfxknmw
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 254;
	
	  ;% rtB.lipu0dbc2k
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 256;
	
	  ;% rtB.mhmxoetwje
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 258;
	
	  ;% rtB.jdqmorg3jr
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 259;
	
	  ;% rtB.j5d2rfynpz
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 271;
	
	  ;% rtB.bgofqzyuag
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 277;
	
	  ;% rtB.hyspkccycp
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 283;
	
	  ;% rtB.fgqxwi1chj
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 289;
	
	  ;% rtB.fz3gjqjow4
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 295;
	
	  ;% rtB.b4h3ks3r0d
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 301;
	
	  ;% rtB.oflhugxayb
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 307;
	
	  ;% rtB.it5y34mzxt
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 311;
	
	  ;% rtB.ksdh1okcet
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 312;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.hpraryzlaj.h0xntzw5zb
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.j2zidd3tqj.gydza50f0o
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.eg12osul0v.h0xntzw5zb
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.feorxccqpz.gydza50f0o
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.lxb4grs0ty.jb4t0dt15b
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ca4s31r1o4.n54ymdd4p0
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.pg0yucqphr.oaqi4nmegi
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.cvltowsf2b.ao4ocy3oo3
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ffhxpulbso.cxgasfu34l
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.ipiqttfm4x.ejjucyteji
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.l1rejasabs.jb4t0dt15b
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.cwezlbfqfz.ejjucyteji
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.n11qfveosl.n54ymdd4p0
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jrhbb2xk4n.oaqi4nmegi
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.paq4dzeup4.ao4ocy3oo3
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtB.jr4hvs211j.cxgasfu34l
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 17;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDW)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% rtDW.lh1jhunvsh
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.ekrugbtxsn
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 6;
	
	  ;% rtDW.iuen2h2uzw
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 12;
	
	  ;% rtDW.gp01wmmidy.modelTStart
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 24;
	
	  ;% rtDW.kdwpr03ybd.modelTStart
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 25;
	
	  ;% rtDW.pmxp5qek5h.modelTStart
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 54;
      section.data(54)  = dumData; %prealloc
      
	  ;% rtDW.l4oivvvvyz.LoggedData
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.jzvi34rmlr.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.ascbhwveph.TUbufferPtrs
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.m5ovno0zss.TUbufferPtrs
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 4;
	
	  ;% rtDW.dx5bxpzipw.TUbufferPtrs
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 6;
	
	  ;% rtDW.ah4xxhij4f.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 8;
	
	  ;% rtDW.hklofzqmuc.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 9;
	
	  ;% rtDW.kie23jbppm.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 10;
	
	  ;% rtDW.p1ppyahmgi.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 11;
	
	  ;% rtDW.d310uncg1y.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 12;
	
	  ;% rtDW.jo3cx5bohy.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 13;
	
	  ;% rtDW.nmdc4rqnwf.LoggedData
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 15;
	
	  ;% rtDW.gqqn5cu3v3.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 16;
	
	  ;% rtDW.fpcaxygowv.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 17;
	
	  ;% rtDW.j3rkq32ahw.LoggedData
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 18;
	
	  ;% rtDW.ecce2dvsos.LoggedData
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 19;
	
	  ;% rtDW.j1o5yxgppi.LoggedData
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 20;
	
	  ;% rtDW.pwowgrrppn.LoggedData
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 21;
	
	  ;% rtDW.ninuxp2rok.LoggedData
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 22;
	
	  ;% rtDW.gcoy2nk0hc.LoggedData
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 23;
	
	  ;% rtDW.kbvzsvjrbk.LoggedData
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 24;
	
	  ;% rtDW.d0yl2k2gt3.LoggedData
	  section.data(22).logicalSrcIdx = 27;
	  section.data(22).dtTransOffset = 25;
	
	  ;% rtDW.jvk5wijwro.LoggedData
	  section.data(23).logicalSrcIdx = 28;
	  section.data(23).dtTransOffset = 26;
	
	  ;% rtDW.c4oxhjn4wm.LoggedData
	  section.data(24).logicalSrcIdx = 29;
	  section.data(24).dtTransOffset = 27;
	
	  ;% rtDW.jqjrqjyjli.LoggedData
	  section.data(25).logicalSrcIdx = 30;
	  section.data(25).dtTransOffset = 28;
	
	  ;% rtDW.aa5gpmhc3a.LoggedData
	  section.data(26).logicalSrcIdx = 31;
	  section.data(26).dtTransOffset = 29;
	
	  ;% rtDW.lvqguxuqdr.LoggedData
	  section.data(27).logicalSrcIdx = 32;
	  section.data(27).dtTransOffset = 30;
	
	  ;% rtDW.o5lhljo4nd.LoggedData
	  section.data(28).logicalSrcIdx = 33;
	  section.data(28).dtTransOffset = 31;
	
	  ;% rtDW.hla0xdzqni.LoggedData
	  section.data(29).logicalSrcIdx = 34;
	  section.data(29).dtTransOffset = 32;
	
	  ;% rtDW.boirfqbbsy.LoggedData
	  section.data(30).logicalSrcIdx = 35;
	  section.data(30).dtTransOffset = 33;
	
	  ;% rtDW.dtaltrldf4.LoggedData
	  section.data(31).logicalSrcIdx = 36;
	  section.data(31).dtTransOffset = 34;
	
	  ;% rtDW.cdnjpny0g4.LoggedData
	  section.data(32).logicalSrcIdx = 37;
	  section.data(32).dtTransOffset = 35;
	
	  ;% rtDW.fo3urnu55t.LoggedData
	  section.data(33).logicalSrcIdx = 38;
	  section.data(33).dtTransOffset = 36;
	
	  ;% rtDW.ebj5iepbj5.LoggedData
	  section.data(34).logicalSrcIdx = 39;
	  section.data(34).dtTransOffset = 37;
	
	  ;% rtDW.di2sxodqb0.LoggedData
	  section.data(35).logicalSrcIdx = 40;
	  section.data(35).dtTransOffset = 38;
	
	  ;% rtDW.eux4lj2epg.LoggedData
	  section.data(36).logicalSrcIdx = 41;
	  section.data(36).dtTransOffset = 39;
	
	  ;% rtDW.iw2kvox1xe.LoggedData
	  section.data(37).logicalSrcIdx = 42;
	  section.data(37).dtTransOffset = 40;
	
	  ;% rtDW.i4u5v5s0km.LoggedData
	  section.data(38).logicalSrcIdx = 43;
	  section.data(38).dtTransOffset = 41;
	
	  ;% rtDW.pju1hy2pt4.LoggedData
	  section.data(39).logicalSrcIdx = 44;
	  section.data(39).dtTransOffset = 42;
	
	  ;% rtDW.emqqixgbtf.LoggedData
	  section.data(40).logicalSrcIdx = 45;
	  section.data(40).dtTransOffset = 43;
	
	  ;% rtDW.oxyc14cgy1.LoggedData
	  section.data(41).logicalSrcIdx = 46;
	  section.data(41).dtTransOffset = 44;
	
	  ;% rtDW.czs5ji1vj4.TimePtr
	  section.data(42).logicalSrcIdx = 47;
	  section.data(42).dtTransOffset = 45;
	
	  ;% rtDW.gcdvojgmqy.TimePtr
	  section.data(43).logicalSrcIdx = 48;
	  section.data(43).dtTransOffset = 46;
	
	  ;% rtDW.nlbag1a2v1.TimePtr
	  section.data(44).logicalSrcIdx = 49;
	  section.data(44).dtTransOffset = 47;
	
	  ;% rtDW.k4aipb3zed.TimePtr
	  section.data(45).logicalSrcIdx = 50;
	  section.data(45).dtTransOffset = 48;
	
	  ;% rtDW.k2xhaupeb3.LoggedData
	  section.data(46).logicalSrcIdx = 51;
	  section.data(46).dtTransOffset = 49;
	
	  ;% rtDW.pdea4rxbko.LoggedData
	  section.data(47).logicalSrcIdx = 52;
	  section.data(47).dtTransOffset = 52;
	
	  ;% rtDW.dxomvattco.LoggedData
	  section.data(48).logicalSrcIdx = 53;
	  section.data(48).dtTransOffset = 54;
	
	  ;% rtDW.ppz3sujyuc.LoggedData
	  section.data(49).logicalSrcIdx = 54;
	  section.data(49).dtTransOffset = 55;
	
	  ;% rtDW.epkhmc0w1c.LoggedData
	  section.data(50).logicalSrcIdx = 55;
	  section.data(50).dtTransOffset = 56;
	
	  ;% rtDW.ebulbgz34l.LoggedData
	  section.data(51).logicalSrcIdx = 56;
	  section.data(51).dtTransOffset = 57;
	
	  ;% rtDW.k5k0a3kpu3.LoggedData
	  section.data(52).logicalSrcIdx = 57;
	  section.data(52).dtTransOffset = 58;
	
	  ;% rtDW.oyuwqi1alg.LoggedData
	  section.data(53).logicalSrcIdx = 58;
	  section.data(53).dtTransOffset = 59;
	
	  ;% rtDW.d1paqxnris.LoggedData
	  section.data(54).logicalSrcIdx = 59;
	  section.data(54).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% rtDW.pnp5xqshxz.Tail
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDW.d2lrwdgt4h.Tail
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDW.cfbh3wuutq.Tail
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDW.bpo0twltjm
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDW.mplujf0x0c
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 5;
	
	  ;% rtDW.phrp5iu5sk.PrevIndex
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 6;
	
	  ;% rtDW.cmi14xe5ec.PrevIndex
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 7;
	
	  ;% rtDW.m5jz3vy2cr.PrevIndex
	  section.data(8).logicalSrcIdx = 67;
	  section.data(8).dtTransOffset = 8;
	
	  ;% rtDW.k20gh5ioaa.PrevIndex
	  section.data(9).logicalSrcIdx = 68;
	  section.data(9).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% rtDW.jfw2terd0g
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1399061238;
  targMap.checksum1 = 1260434799;
  targMap.checksum2 = 1108173927;
  targMap.checksum3 = 2886202868;

